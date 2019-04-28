#include "renderer.hpp"

#include <glad/glad.h>
#include <ui/opengl_context.hpp>

#include <mutex>
#include <stdexcept>
#include <string_view>

#include "log.hpp"
#include "framebuffer.hpp"
#include "program_pipeline.hpp"
#include "sampler.hpp"
#include "texture.hpp"
#include "vertex_array_object.hpp"

namespace gfx::gl
{
	struct renderer_error : public std::runtime_error
	{
	public:
		renderer_error(const std::string &what) : std::runtime_error(what)
		{
		}
	};

	namespace
	{
		static constexpr GLenum features[] = {
			GL_BLEND,
			GL_CULL_FACE,
			GL_DEBUG_OUTPUT,
			GL_DEPTH_TEST,
			GL_DITHER,
			GL_POLYGON_OFFSET_FILL,
			GL_PRIMITIVE_RESTART_FIXED_INDEX,
			GL_RASTERIZER_DISCARD,
			GL_SAMPLE_ALPHA_TO_COVERAGE,
			GL_SAMPLE_COVERAGE,
			GL_SAMPLE_MASK,
			GL_SCISSOR_TEST,
			GL_STENCIL_TEST
		};

		static constexpr GLenum blend_functions[] = {
			GL_ZERO,
			GL_ONE,
			GL_SRC_COLOR,
			GL_ONE_MINUS_SRC_COLOR,
			GL_DST_COLOR,
			GL_ONE_MINUS_DST_COLOR,
			GL_SRC_ALPHA,
			GL_ONE_MINUS_SRC_ALPHA,
			GL_DST_ALPHA,
			GL_ONE_MINUS_DST_ALPHA,
			GL_CONSTANT_COLOR,
			GL_ONE_MINUS_CONSTANT_COLOR,
			GL_CONSTANT_ALPHA,
			GL_ONE_MINUS_CONSTANT_ALPHA,
			GL_SRC_ALPHA_SATURATE
		};

		static constexpr GLenum equations[] = {
			GL_FUNC_ADD,
			GL_FUNC_SUBTRACT,
			GL_FUNC_REVERSE_SUBTRACT,
			GL_MIN,
			GL_MAX
		};
		
		static constexpr GLenum draw_modes[] = {
			GL_POINTS,
			GL_LINES,
			GL_LINE_LOOP,
			GL_LINE_STRIP,
			GL_TRIANGLES,
			GL_TRIANGLE_STRIP,
			GL_TRIANGLE_FAN,
		};

		static constexpr GLenum index_types[] = {
			GL_UNSIGNED_BYTE,
			GL_UNSIGNED_SHORT,
			GL_UNSIGNED_INT,
		};

		static constexpr size_t bytes_per_element[] =
		{
			1, // uint8
			2, // uint16
			4, // uint32
		};

		static constexpr GLenum to_gl(feature feature) noexcept
		{
			return features[static_cast<size_t>(feature)];
		}

		static constexpr GLenum to_gl(blend_function function) noexcept
		{
			return blend_functions[static_cast<size_t>(function)];
		}

		static const GLenum to_gl(blend_equation equation) noexcept
		{
			return equations[static_cast<size_t>(equation)];
		}

		static constexpr GLenum to_gl(draw_mode mode) noexcept
		{
			return draw_modes[static_cast<size_t>(mode)];
		}

		static constexpr GLenum to_gl(index_type type) noexcept
		{
			return index_types[static_cast<size_t>(type)];
		}

		static constexpr size_t size(index_type type) noexcept
		{
			return bytes_per_element[static_cast<size_t>(type)];
		}

		static constexpr size_t index_offset(size_t start, index_type type)
		{
			return start * size(type);
		}

		static void *index_offset_ptr(size_t start, index_type type)
		{
			return reinterpret_cast<void *>(index_offset(start, type));
		}

		static constexpr spdlog::level::level_enum from_severity(GLenum severity) noexcept
		{
			return severity == GL_DEBUG_SEVERITY_NOTIFICATION ? spdlog::level::debug
				: severity == GL_DEBUG_SEVERITY_LOW ? spdlog::level::info
				: severity == GL_DEBUG_SEVERITY_MEDIUM ? spdlog::level::warn
				: severity == GL_DEBUG_SEVERITY_HIGH ? spdlog::level::err
				: spdlog::level::critical;
		}

		static constexpr std::string_view from_source(GLenum source) noexcept
		{
			using namespace std::string_view_literals;

			std::string_view result;

			switch (source)
			{
			default:
				result = "UNKNOWN"sv;
				break;
			case GL_DEBUG_SOURCE_API:
				result = "API"sv;
				break;
			case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
				result = "PLATFORM"sv;
				break;
			case GL_DEBUG_SOURCE_SHADER_COMPILER:
				result = "COMPILER"sv;
				break;
			case GL_DEBUG_SOURCE_THIRD_PARTY:
				result = "THIRD PARTY"sv;
				break;
			case GL_DEBUG_SOURCE_APPLICATION:
				result = "APPLICATION"sv;
				break;
			case GL_DEBUG_SOURCE_OTHER:
				result = "OTHER"sv;
				break;
			}
			return result;
		}

		static std::string_view from_type(GLenum type) noexcept
		{
			using namespace std::string_view_literals;

			std::string_view result;

			switch (type)
			{
			default:
				result = "UNKNOWN"sv;
				break;
			case GL_DEBUG_TYPE_ERROR:
				result = "ERROR"sv;
				break;
			case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
				result = "DEPRECATED"sv;
				break;
			case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
				result = "UNDEFINED"sv;
				break;
			case GL_DEBUG_TYPE_PORTABILITY:
				result = "PORTABILITY"sv;
				break;
			case GL_DEBUG_TYPE_PERFORMANCE:
				result = "PERFORMANCE"sv;
				break;
			case GL_DEBUG_TYPE_OTHER:
				result = "OTHER"sv;
				break;
			case GL_DEBUG_TYPE_MARKER:
				result = "MARKER"sv;
				break;
			case GL_DEBUG_TYPE_PUSH_GROUP:
				result = "PUSH GROUP"sv;
				break;
			case GL_DEBUG_TYPE_POP_GROUP:
				result = "POP GROUP"sv;
				break;
			}

			return result;
		}

		static void APIENTRY on_gl_debug_message(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *user_data)
		{
			auto *logger = static_cast<core::logger *>(const_cast<void*>(user_data));
			(*logger)->log(from_severity(severity), "({0} {1}): {2} - {3}", from_source(source), from_type(type), id, std::string_view(message, length));
		}

		static void load_opengl(GLADloadproc load_proc) noexcept
		{
			struct load_error : std::runtime_error { using std::runtime_error::runtime_error; };

			auto do_load = [](auto load_proc)
			{
				LOG_INFO("Initializing OpenGL");

				if (!gladLoadGLES2Loader(load_proc))
					throw load_error("Failed to load OpenGL");

				LOG_INFO("OpenGL version: {0}", glGetString(GL_VERSION));
				LOG_INFO("OpenGL shader version: {0}", glGetString(GL_SHADING_LANGUAGE_VERSION));
				LOG_INFO("OpenGL vendor: {0}", glGetString(GL_VENDOR));
				LOG_INFO("OpenGL renderer: {0}", glGetString(GL_RENDERER));
			};

			try
			{
				static std::once_flag once_flag;
				std::call_once(once_flag, do_load, load_proc);
			}
			catch (const load_error &e)
			{
				LOG_ERROR("{}", e.what());
			}
		}
	}

	renderer::renderer(const ui::opengl_context &context) noexcept
		: gl_logger(core::register_logger("GL"))
	{
		gl_logger->set_pattern("[%T] [%^%n%$] %v");

		load_opengl(context.get_load_proc());

		glDebugMessageCallback(on_gl_debug_message, &gl_logger);
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, nullptr, GL_FALSE);
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_LOW, 0, nullptr, GL_TRUE);
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_MEDIUM, 0, nullptr, GL_TRUE);
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_HIGH, 0, nullptr, GL_TRUE);
		// TODO: Disable in release builds?
		glEnable(GL_DEBUG_OUTPUT);
		glDisable(GL_DEBUG_OUTPUT_SYNCHRONOUS);

		glEnable(GL_FRAMEBUFFER_SRGB_EXT);
		GLint enc;
		glGetFramebufferAttachmentParameteriv(GL_DRAW_FRAMEBUFFER, GL_BACK, GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING, &enc);
		LOG_INFO("framebuffer encoding is {0}", enc == GL_SRGB ? "sRGB" : GL_LINEAR ? "linear" : "unknown");

		int size;
		glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &size);
		active_texture_bindings.resize(size);

		set_viewport({0, 0}, context.drawable_size());

		enable(feature::depth_test);
		set_clear_depth(1.0);
		glDepthFunc(GL_LEQUAL);

		enable(feature::face_culling);
		glFrontFace(GL_CCW);

	}

	void renderer::enable(feature feature) noexcept
	{
		glEnable(to_gl(feature));
	}

	void renderer::disable(feature feature) noexcept
	{
		glDisable(to_gl(feature));
	}

	void renderer::set_viewport(const glm::ivec2 &p, const glm::ivec2 &size) noexcept
	{
		glViewport(p.x, p.y, size.x, size.y);
	}

	void renderer::set_blend_color(float r, float g, float b, float a) noexcept
	{
		glBlendColor(r, g, b, a);
	}

	void renderer::set_blend_function(blend_function source, blend_function dest) noexcept
	{
		glBlendFunc(to_gl(source), to_gl(dest));
	}

	void renderer::set_blend_function(blend_function rgbSource, blend_function rgbDest, blend_function alphaSource, blend_function alphaDest) noexcept
	{
		glBlendFuncSeparate(to_gl(rgbSource), to_gl(rgbDest), to_gl(alphaSource), to_gl(alphaDest));
	}

	void renderer::set_blend_equation(blend_equation equation) noexcept
	{
		glBlendEquation(to_gl(equation));
	}

	void renderer::set_blend_equation(blend_equation rgb, blend_equation alpha) noexcept
	{
		glBlendEquationSeparate(to_gl(rgb), to_gl(alpha));
	}

	void renderer::set_clear_color(float r, float g, float b, float a) noexcept
	{
		glClearColor(r, g, b, a);
	}

	void renderer::set_clear_depth(float depth) noexcept
	{
		glClearDepthf(depth);
	}
	
	void renderer::set_clear_stencil(int stencil) noexcept
	{
		glClearStencil(stencil);
	}

	void renderer::clear_color() noexcept
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void renderer::clear_depth() noexcept
	{
		glClear(GL_DEPTH_BUFFER_BIT);
	}

	void renderer::clear_stencil() noexcept
	{
		glClear(GL_STENCIL_BUFFER_BIT);
	}

	void renderer::use_vertex_array_object(const vertex_array_object &vao) noexcept
	{
		vao.bind_unsafe();
	}

	void renderer::clear_vertex_array_object() noexcept
	{
		vertex_array_object::unbind_unsafe();
	}

	void renderer::use_program_pipeline(program_pipeline &pipeline) noexcept
	{
		pipeline.unsafe_bind();
	}
	
	void renderer::clear_program_pipeline() noexcept
	{
		program_pipeline::unsafe_unbind();
	}

	void renderer::use_texture(int texture_unit, texture &texture, sampler &sampler) noexcept
	{
		glActiveTexture(GL_TEXTURE0 + texture_unit);
		active_texture_bindings[texture_unit] = texture.unsafe_bind();
		sampler.unsafe_bind(texture_unit);
	}
	
	void renderer::clear_texture(int texture_unit) noexcept
	{
		glActiveTexture(GL_TEXTURE0 + texture_unit);
		glBindTexture(active_texture_bindings[texture_unit], 0);
		glBindSampler(texture_unit, 0);
		active_texture_bindings[texture_unit] = 0;
	}

	void renderer::use_framebuffer(framebuffer_target target, framebuffer &buffer) noexcept
	{
		buffer.unsafe_bind(target);
	}
	
	void renderer::clear_framebuffer(framebuffer_target target) noexcept
	{
		framebuffer::unsafe_unbind(target);
	}

	void renderer::draw(draw_mode mode, size_t start, size_t count) noexcept
	{
		glDrawArrays(to_gl(mode), static_cast<GLint>(start), static_cast<GLsizei>(count));
	}

	void renderer::draw_indexed(draw_mode mode, index_type type, size_t start, size_t count) noexcept
	{
		glDrawElements(to_gl(mode), static_cast<GLsizei>(count), to_gl(type), index_offset_ptr(start, type));
	}

	void renderer::draw_instances_indexed(draw_mode mode, index_type type, size_t start, size_t count, size_t instances) noexcept
	{
		glDrawElementsInstanced(to_gl(mode), static_cast<GLsizei>(count), to_gl(type), index_offset_ptr(start, type), static_cast<GLsizei>(instances));
	}

	void renderer::blit_to_surface(framebuffer &buffer, glm::ivec2 src_p1, glm::ivec2 src_p2, glm::ivec2 dest_p1, glm::ivec2 dest_p2) noexcept
	{
		// unbind the draw framebuffer (sets our draw target to the main surface)
		framebuffer::unsafe_unbind(framebuffer_target::draw);
		buffer.unsafe_bind(framebuffer_target::read);
		glBlitFramebuffer(
			src_p1.x, src_p1.y, src_p2.x, src_p2.y,
			dest_p1.x, dest_p1.y, dest_p2.x, dest_p2.y,
			GL_COLOR_BUFFER_BIT, GL_LINEAR);
	}
}

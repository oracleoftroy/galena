#include "sampler.hpp"

#include <utility>
#include <glm/gtc/type_ptr.hpp>

#include <glad/glad.h>

namespace gfx::gl
{
	namespace
	{
		//static constexpr GLint parameter_names[] =
		//{
		//	GL_TEXTURE_WRAP_S,
		//	GL_TEXTURE_WRAP_T,
		//	GL_TEXTURE_WRAP_R,

		//	GL_TEXTURE_MIN_FILTER,
		//	GL_TEXTURE_MAG_FILTER,

		//	GL_TEXTURE_MIN_LOD,
		//	GL_TEXTURE_MAX_LOD,

		//	GL_TEXTURE_COMPARE_MODE,
		//	GL_TEXTURE_COMPARE_FUNC
		//};

		static constexpr GLint texture_filters[] =
		{
			GL_NEAREST,
			GL_LINEAR,
			GL_NEAREST_MIPMAP_NEAREST,
			GL_LINEAR_MIPMAP_NEAREST,
			GL_NEAREST_MIPMAP_LINEAR,
			GL_LINEAR_MIPMAP_LINEAR
		};

		static constexpr GLint texture_wrap_modes[] =
		{
			GL_CLAMP_TO_EDGE,
			GL_MIRRORED_REPEAT,
			GL_REPEAT,
			GL_CLAMP_TO_BORDER
		};

		static constexpr GLint compare_modes[] =
		{
			GL_NONE,
			GL_COMPARE_REF_TO_TEXTURE
		};

		static constexpr GLint compare_funcs[] =
		{
			GL_LEQUAL,
			GL_GEQUAL,
			GL_LESS,
			GL_GREATER,
			GL_EQUAL,
			GL_NOTEQUAL,
			GL_ALWAYS,
			GL_NEVER
		};

		static constexpr GLint to_gl(minify_filter filter) noexcept
		{
			return texture_filters[static_cast<size_t>(filter)];
		}

		static constexpr GLint to_gl(magnify_filter filter) noexcept
		{
			return texture_filters[static_cast<size_t>(filter)];
		}

		static constexpr GLint to_gl(texture_wrap_mode wrap_mode) noexcept
		{
			return texture_wrap_modes[static_cast<size_t>(wrap_mode)];
		}

		static constexpr GLint to_gl(compare_mode mode) noexcept
		{
			return compare_modes[static_cast<size_t>(mode)];
		}

		static constexpr GLint to_gl(compare_function function) noexcept
		{
			return compare_funcs[static_cast<size_t>(function)];
		}
	}

	sampler sampler::create() noexcept
	{
		return sampler(sampler_resource::create());
	}
	
	sampler::sampler(sampler_resource &&resource) : resource(std::move(resource))
	{
	}
	
	void sampler::use_filter(minify_filter filter) noexcept
	{
		glSamplerParameteri(resource, GL_TEXTURE_MIN_FILTER, to_gl(filter));
	}

	void sampler::use_filter(magnify_filter filter) noexcept
	{
		glSamplerParameteri(resource, GL_TEXTURE_MAG_FILTER, to_gl(filter));
	}

	void sampler::min_lod(int lod) noexcept
	{
		glSamplerParameteri(resource, GL_TEXTURE_MIN_LOD, lod);
	}

	void sampler::max_lod(int lod) noexcept
	{
		glSamplerParameteri(resource, GL_TEXTURE_MAX_LOD, lod);
	}

	void sampler::wrap(texture_wrap wrap) noexcept
	{
		glSamplerParameteri(resource, GL_TEXTURE_WRAP_S, to_gl(wrap.s));
		glSamplerParameteri(resource, GL_TEXTURE_WRAP_T, to_gl(wrap.t));
		glSamplerParameteri(resource, GL_TEXTURE_WRAP_R, to_gl(wrap.r));
	}

	void sampler::use_compare_mode(compare_mode mode) noexcept
	{
		glSamplerParameteri(resource, GL_TEXTURE_COMPARE_MODE, to_gl(mode));
	}

	void sampler::use_compare_function(compare_function function) noexcept
	{
		glSamplerParameteri(resource, GL_TEXTURE_COMPARE_FUNC, to_gl(function));
	}

	void sampler::border_color(glm::vec4 color) noexcept
	{
		glSamplerParameterfv(resource, GL_TEXTURE_BORDER_COLOR, glm::value_ptr(color));
	}

	void sampler::unsafe_bind(uint32_t texture_unit) noexcept
	{
		glBindSampler(texture_unit, resource);
	}

	uint32_t sampler::create_sampler() noexcept
	{
		GLuint sampler;
		glGenSamplers(1, &sampler);
		return sampler;
	}
	
	void sampler::destroy_sampler(uint32_t sampler) noexcept
	{
		glDeleteSamplers(1, &sampler);
	}
}

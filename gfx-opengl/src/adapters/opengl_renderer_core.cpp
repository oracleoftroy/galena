#include <gfx/gl/opengl_renderer_core.hpp>

#include <gfx/buffer.hpp>
#include <gfx/renderer.hpp>

#include "opengl_buffer_core.hpp"
#include "opengl_mesh_core.hpp"
#include "opengl_program_core.hpp"
#include "opengl_pipeline_core.hpp"
#include "opengl_imgui_graphics.hpp"

#include "../renderer.hpp"

namespace gfx::gl::detail
{
	class opengl_renderer_core final : public gfx::renderer_core
	{
	public:
		explicit opengl_renderer_core(ui::opengl_context &context) noexcept;

		void set_viewport(const glm::ivec2 &p, const glm::ivec2 &size) noexcept override;
		void set_clear_color(float r, float g, float b, float a) noexcept override;
		void clear_color() noexcept override;
		void clear_depth() noexcept;

		gfx::buffer create_buffer(gfx::buffer_type type, gfx::usage_hint hint, const void *data, size_t size) override;
		gfx::program create_program(gfx::program_type type, const fs::path &file_path) override;
		gfx::pipeline create_pipeline() override;
		gfx::mesh create_mesh(const std::initializer_list<buffer_description> &descriptions) override;
		std::unique_ptr<gfx::imgui::imgui_graphics_core> create_imgui_graphics_core() override;

		void use_pipeline(gfx::pipeline &pipeline) override;
		void draw_indexed_mesh(const gfx::mesh &m, gfx::draw_mode mode, gfx::index_type type, int start, int count) override;

	private:
		gl::renderer renderer;
	};
}

namespace gfx::gl
{
	gfx::renderer create_opengl_renderer(ui::opengl_context &context) noexcept
	{
		return gfx::renderer(std::make_unique<detail::opengl_renderer_core>(context));
	}
}

namespace gfx::gl::detail
{
	opengl_renderer_core::opengl_renderer_core(ui::opengl_context &context) noexcept
		: renderer(context)
	{
	}

	void opengl_renderer_core::set_viewport(const glm::ivec2 &p, const glm::ivec2 &size) noexcept
	{
		renderer.set_viewport(p, size);
	}

	void opengl_renderer_core::set_clear_color(float r, float g, float b, float a) noexcept
	{
		renderer.set_clear_color(r, g, b, a);
	}

	void opengl_renderer_core::clear_color() noexcept
	{
		renderer.clear_color();
	}

	void opengl_renderer_core::clear_depth() noexcept
	{
		renderer.clear_depth();
	}

	gfx::buffer opengl_renderer_core::create_buffer(gfx::buffer_type type, gfx::usage_hint hint, const void *data, size_t size)
	{
		return gfx::buffer{opengl_buffer_core::create(type, hint, data, size)};
	}

	gfx::program opengl_renderer_core::create_program(gfx::program_type type, const fs::path &file_path)
	{
		return gfx::program{opengl_program_core::create(type, file_path)};
	}

	gfx::pipeline opengl_renderer_core::create_pipeline()
	{
		return gfx::pipeline{opengl_pipeline_core::create()};
	}

	gfx::mesh opengl_renderer_core::create_mesh(const std::initializer_list<buffer_description> &descriptions)
	{
		return gfx::mesh{opengl_mesh_core::create(descriptions)};
	}

	std::unique_ptr<gfx::imgui::imgui_graphics_core> opengl_renderer_core::create_imgui_graphics_core()
	{
		return std::make_unique<gl::imgui::opengl_imgui_graphics>();
	}

	void opengl_renderer_core::use_pipeline(gfx::pipeline &pipeline)
	{
		auto &pipeline_core = static_cast<opengl_pipeline_core &>(*pipeline);
		renderer.use_program_pipeline(pipeline_core.get());
	}

	void opengl_renderer_core::draw_indexed_mesh(const gfx::mesh &m, gfx::draw_mode mode, gfx::index_type type, int start, int count)
	{
		const opengl_mesh_core &mesh = static_cast<const opengl_mesh_core &>(*m);
		mesh.draw_indexed(renderer, mode, type, start, count);
	}
}

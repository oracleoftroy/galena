#include <gfx/gl/opengl_renderer_core.hpp>

#include <gfx/renderer.hpp>

#include "renderer.hpp"
#include "imgui_graphics.hpp"

namespace gfx::gl
{
	class opengl_renderer_core
	{
	public:
		opengl_renderer_core(ui::opengl_context &context) noexcept
			: renderer(context)
		{
		}

		gl::renderer renderer;
	};

	void opengl_renderer_core_deleter::operator()(opengl_renderer_core *ptr) const
	{
		delete ptr;
	}

	opengl_renderer create_opengl_renderer(ui::opengl_context &context) noexcept
	{
		using ptr = std::unique_ptr<opengl_renderer_core, opengl_renderer_core_deleter>;
		return opengl_renderer(ptr(new opengl_renderer_core(context)));
	}

	void do_set_viewport(opengl_renderer_core &core, const glm::ivec2 &p, const glm::ivec2 &size) noexcept
	{
		core.renderer.set_viewport(p, size);
	}

	void do_set_clear_color(opengl_renderer_core &core, float r, float g, float b, float a) noexcept
	{
		core.renderer.set_clear_color(r, g, b, a);
	}

	void do_clear_color(opengl_renderer_core &core) noexcept
	{
		core.renderer.clear_color();
	}

	std::unique_ptr<gfx::imgui::imgui_graphics_core> do_create_imgui_graphics_core([[maybe_unused]]opengl_renderer_core &core) noexcept
	{
		return std::make_unique<imgui::imgui_graphics>();
	}
}

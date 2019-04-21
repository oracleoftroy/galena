#include <gfx/renderer.hpp>
#include <gfx/imgui_graphics.hpp>

namespace gfx
{
	void renderer::set_viewport(const glm::ivec2 &p, const glm::ivec2 &size) noexcept
	{
		base->set_viewport(p, size);
	}

	void renderer::set_clear_color(float r, float g, float b, float a) noexcept
	{
		base->set_clear_color(r, g, b, a);
	}

	void renderer::clear_color() noexcept
	{
		base->clear_color();
	}

	std::unique_ptr<imgui::imgui_graphics_core> renderer::create_imgui_graphics_core() noexcept
	{
		return base->create_imgui_graphics_core();
	}
}

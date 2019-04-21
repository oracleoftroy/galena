#include "imgui.hpp"

#include <gfx/renderer.hpp>

namespace app
{
	imgui::imgui(ui::opengl_context &context, gfx::renderer &renderer) noexcept
		: system(context), graphics(renderer.create_imgui_graphics_core())
	{
	}

	void imgui::new_frame() noexcept
	{
		graphics.new_frame();
		system.new_frame();
	}

	void imgui::render() noexcept
	{
		system.render();
		graphics.render();
	}
}

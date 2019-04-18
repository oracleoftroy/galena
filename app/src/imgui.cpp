#include "imgui.hpp"

#include <gfx/renderer.hpp>

namespace app
{
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

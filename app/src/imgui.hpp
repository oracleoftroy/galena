#pragma once

#include <ui/imgui_system.hpp>
#include <gfx/imgui_graphics.hpp>

namespace gfx
{
	class renderer;
}

namespace app
{
	class imgui
	{
	public:
		imgui(ui::opengl_context &context, gfx::renderer &renderer) noexcept;
		~imgui() noexcept = default;

		void new_frame() noexcept;
		void render() noexcept;

		imgui(imgui &&other) noexcept = delete;
		imgui &operator=(imgui &&other) noexcept = delete;
		imgui(const imgui &other) noexcept = delete;
		imgui &operator=(const imgui &other) noexcept = delete;

	private:
		ui::imgui::imgui_system system;
		gfx::imgui::imgui_graphics graphics;
	};
}

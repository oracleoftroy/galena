#pragma once

#include <gfx/imgui_graphics.hpp>

namespace gfx::gl::imgui
{
	class imgui_graphics final : public gfx::imgui::imgui_graphics_core
	{
	public:
		imgui_graphics() noexcept;
		~imgui_graphics() noexcept override;
		void new_frame() noexcept override;
		void render() noexcept override;

		imgui_graphics(imgui_graphics &&other) noexcept = delete;
		imgui_graphics &operator=(imgui_graphics &&other) noexcept = delete;
		imgui_graphics(const imgui_graphics &other) noexcept = delete;
		imgui_graphics &operator=(const imgui_graphics &other) noexcept = delete;
	};
}

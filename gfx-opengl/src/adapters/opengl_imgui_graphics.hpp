#pragma once

#include <gfx/imgui_graphics.hpp>

namespace gfx::gl::imgui
{
	class opengl_imgui_graphics final : public gfx::imgui::imgui_graphics_core
	{
	public:
		opengl_imgui_graphics() noexcept;
		~opengl_imgui_graphics() override;

		void new_frame() noexcept override;
		void render() noexcept override;
	};
}

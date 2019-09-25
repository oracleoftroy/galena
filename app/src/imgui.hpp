#pragma once

#include <ui/imgui_system.hpp>
#include <gfx/imgui_graphics.hpp>

namespace gfx
{
	class renderer;
}

namespace ui
{
	class opengl_context;
	class vulkan_context;
}

namespace app
{
	template <typename Context>
	class imgui
	{
	public:
		imgui(Context &context, gfx::renderer &renderer) noexcept;

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

	template <typename Context>
	imgui<Context>::imgui(Context &context, gfx::renderer &renderer) noexcept
		: system(context), graphics(renderer.create_imgui_graphics_core())
	{
	}

	template <typename Context>
	void imgui<Context>::new_frame() noexcept
	{
		graphics.new_frame();
		system.new_frame();
	}

	template <typename Context>
	void imgui<Context>::render() noexcept
	{
		system.render();
		graphics.render();
	}
}

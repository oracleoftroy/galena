#pragma once

#include <memory>

namespace gfx::imgui
{
	class imgui_graphics_core
	{
	public:
		imgui_graphics_core() noexcept = default;
		virtual ~imgui_graphics_core() = default;

		virtual void new_frame() noexcept = 0;
		virtual void render() noexcept = 0;

		imgui_graphics_core(imgui_graphics_core &&other) noexcept = delete;
		imgui_graphics_core &operator=(imgui_graphics_core &&other) noexcept = delete;
		imgui_graphics_core(const imgui_graphics_core &other) noexcept = delete;
		imgui_graphics_core &operator=(const imgui_graphics_core &other) noexcept = delete;
	};

	class imgui_graphics final
	{
	public:
		explicit imgui_graphics(std::unique_ptr<imgui_graphics_core> &&data) noexcept
			: data(std::move(data))
		{
		}

		void new_frame() noexcept
		{
			data->new_frame();
		}

		void render() noexcept
		{
			data->render();
		}

	private:
		std::unique_ptr<imgui_graphics_core> data;
	};
}

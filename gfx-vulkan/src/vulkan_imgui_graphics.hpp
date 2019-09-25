#pragma once

#include <gfx/imgui_graphics.hpp>

namespace gfx::vk::detail
{
	class vulkan_renderer_core;
}

namespace gfx::vk::imgui
{
	class vulkan_imgui_graphics final : public gfx::imgui::imgui_graphics_core
	{
	public:
		vulkan_imgui_graphics(const detail::vulkan_renderer_core &core) noexcept;
		~vulkan_imgui_graphics() override;

		void new_frame() noexcept override;
		void render() noexcept override;

	private:
		const detail::vulkan_renderer_core &renderer_core;
	};
}

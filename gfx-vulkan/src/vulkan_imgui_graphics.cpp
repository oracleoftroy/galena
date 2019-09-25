#include "vulkan_imgui_graphics.hpp"

#include "vulkan_renderer_core.hpp"
#include <imgui.h>
#include <imgui_impl_vulkan.h>

namespace gfx::vk::imgui
{
	vulkan_imgui_graphics::vulkan_imgui_graphics(const vk::detail::vulkan_renderer_core &core) noexcept
		: renderer_core(core)
	{
		ImGui_ImplVulkan_InitInfo info{};
		ImGui_ImplVulkan_Init(&info, renderer_core.get_render_pass());
	}

	vulkan_imgui_graphics::~vulkan_imgui_graphics()
	{
		ImGui_ImplVulkan_Shutdown();
	}

	void vulkan_imgui_graphics::new_frame() noexcept
	{
		ImGui_ImplVulkan_NewFrame();
	}

	void vulkan_imgui_graphics::render() noexcept
	{
		ImGui_ImplVulkan_RenderDrawData(ImGui::GetDrawData(), renderer_core.get_current_command_buffer());
	}
}

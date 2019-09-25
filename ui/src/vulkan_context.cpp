#include <ui/vulkan_context.hpp>

#include "platform_info.hpp"
#include UI_VULKAN_CONTEXT_H

#include <utility>


namespace ui
{
	vulkan_context::vulkan_context(std::unique_ptr<vulkan_context_core> &&core)
		: core(std::move(core))
	{
	}

	vulkan_context::~vulkan_context() = default;

	// these should be defaulted in the header, but MSVC complains about deleting an incomplete type
	vulkan_context::vulkan_context(vulkan_context &&) noexcept = default;
	vulkan_context &vulkan_context::operator=(vulkan_context &&) noexcept = default;

	std::vector<const char *> vulkan_context::required_extensions() const
	{
		return core->required_extensions();
	}

	VkSurfaceKHR vulkan_context::create_surface(VkInstance instance) noexcept
	{
		return core->create_surface(instance);
	}

	glm::ivec2 vulkan_context::drawable_size() const noexcept
	{
		return core->drawable_size();
	}

	PFN_vkGetInstanceProcAddr vulkan_context::get_load_function() noexcept
	{
		return core->get_load_function();
	}
}

#include "sdl_vulkan_context.hpp"

#include <SDL2/SDL_Vulkan.h>

#include "../log.hpp"
#include "sdl_util.hpp"

namespace ui
{
	vulkan_context::vulkan_context_core::vulkan_context_core(SDL_Window *window) noexcept
		: window(window)
	{
	}

	std::vector<const char*> vulkan_context::vulkan_context_core::required_extensions() const
	{
		unsigned int count = 0;
		SDL_VERIFY(SDL_Vulkan_GetInstanceExtensions(window, &count, nullptr));

		std::vector<const char *> result(count);
		SDL_VERIFY(SDL_Vulkan_GetInstanceExtensions(window, &count, result.data()));

		return result;
	}

	VkSurfaceKHR vulkan_context::vulkan_context_core::create_surface(VkInstance instance) noexcept
	{
		VkSurfaceKHR surface;
		SDL_REPORT(SDL_Vulkan_CreateSurface(window, instance, &surface));
		return surface;
	}

	glm::ivec2 vulkan_context::vulkan_context_core::drawable_size() const noexcept
	{
		int w, h;
		SDL_Vulkan_GetDrawableSize(window, &w, &h);
		return {w, h};
	}

	PFN_vkGetInstanceProcAddr vulkan_context::vulkan_context_core::get_load_function() noexcept
	{
		return static_cast<PFN_vkGetInstanceProcAddr>(SDL_Vulkan_GetVkGetInstanceProcAddr());
	}
}

#pragma once

#include <memory>
#include <vector>

#include <glm/glm.hpp>

#if !defined(VULKAN_H) 
// forward declare vulkan types so that clients aren't polluted with the full vulkan api
struct VkInstance_T;
struct VkSurfaceKHR_T;

using VkInstance = VkInstance_T *;
using VkSurfaceKHR = VkSurfaceKHR_T *;

#if defined(_WIN32)
#define VKAPI_PTR __stdcall
#else
#define VKAPI_PTR
#endif

using PFN_vkVoidFunction = void (VKAPI_PTR *)();
using PFN_vkGetInstanceProcAddr = PFN_vkVoidFunction(VKAPI_PTR *)(VkInstance instance, const char *name);
#endif

namespace ui
{
	namespace imgui { class imgui_system; }

	class vulkan_context final
	{
	public:
		vulkan_context() = default;
		~vulkan_context();

		std::vector<const char *> required_extensions() const;
		VkSurfaceKHR create_surface(VkInstance instance) noexcept;
		glm::ivec2 drawable_size() const noexcept;
		PFN_vkGetInstanceProcAddr get_load_function() noexcept;

		vulkan_context(vulkan_context &&) noexcept;
		vulkan_context &operator=(vulkan_context &&) noexcept;
		vulkan_context(const vulkan_context &) noexcept = delete;
		vulkan_context &operator=(const vulkan_context &) noexcept = delete;

	private:
		class vulkan_context_core;
		std::unique_ptr<vulkan_context_core> core;

	private:
		friend class window;
		friend class imgui::imgui_system;

		explicit vulkan_context(std::unique_ptr<vulkan_context_core> &&core);
	};
}

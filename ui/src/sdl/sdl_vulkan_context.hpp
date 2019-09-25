#include <ui/vulkan_context.hpp>

struct SDL_Window;

namespace ui
{
	class vulkan_context::vulkan_context_core
	{
	public:
		vulkan_context_core(SDL_Window *window) noexcept;

		std::vector<const char *> required_extensions() const;
		VkSurfaceKHR create_surface(VkInstance instance) noexcept;
		glm::ivec2 drawable_size() const noexcept;
		PFN_vkGetInstanceProcAddr get_load_function() noexcept;

	private:
		friend class imgui::imgui_system;
		SDL_Window *window;
	};
}

#pragma once

#include <string>
#include <glm/glm.hpp>
#include <ui/window.hpp>
#include <ui/vulkan_context.hpp>

namespace ui
{
	class platform;
}

namespace gfx
{
	class renderer;
}

namespace app
{
	template <typename>
	class imgui;

	using vulkan_imgui = imgui<ui::vulkan_context>;

	class vulkan_backend final
	{
	public:
		[[nodiscard]] static vulkan_backend create(ui::platform &platform, const std::string &title, int width, int height, ui::window_mode flags);
		vulkan_backend() noexcept = default;

		gfx::renderer create_renderer() noexcept;
		vulkan_imgui create_imgui(gfx::renderer &renderer) noexcept;

		glm::ivec2 drawable_size() const noexcept;
		ui::vulkan_context &get_context() noexcept;

		void present() noexcept;

	private:
		vulkan_backend(ui::window &&window, ui::vulkan_context &&context) noexcept;

		ui::window window;
		ui::vulkan_context context;
	};
}

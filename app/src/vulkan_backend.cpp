#include "vulkan_backend.hpp"

#include <utility>
#include <gfx/renderer.hpp>
#include <gfx/vk/vulkan_renderer_core.hpp>
#include <ui/platform.hpp>
#include <ui/window.hpp>
#include <ui/vulkan_context.hpp>
#include "imgui.hpp"

#include "log.hpp"

namespace app
{
	vulkan_backend vulkan_backend::create(ui::platform &platform, const std::string &title, int width, int height, ui::window_mode flags)
	{
		auto window = platform.create_window(title, width, height, flags, ui::gfx_engine::vulkan);
		auto context = window.vulkan_create_context();

		return {std::move(window), std::move(context)};
	}

	vulkan_backend::vulkan_backend(ui::window &&window, ui::vulkan_context &&context) noexcept
		: window(std::move(window)), context(std::move(context))
	{
	}

	gfx::renderer vulkan_backend::create_renderer() noexcept
	{
		return gfx::vk::create_vulkan_renderer(context);
	}

	vulkan_imgui vulkan_backend::create_imgui(gfx::renderer &renderer) noexcept
	{
		return app::imgui(context, renderer);
	}

	glm::ivec2 vulkan_backend::drawable_size() const noexcept
	{
		return context.drawable_size();
	}

	ui::vulkan_context &vulkan_backend::get_context() noexcept
	{
		return context;
	}

	void vulkan_backend::present() noexcept
	{
		LOG_CRITICAL("IMPLEMENT ME!!!");
	}
}

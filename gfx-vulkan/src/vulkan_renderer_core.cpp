#include "vulkan_renderer_core.hpp"

#include <gfx/renderer.hpp>
#include <gfx/buffer.hpp>
#include <gfx/pipeline.hpp>
#include <gfx/mesh.hpp>
#include <gfx/imgui_graphics.hpp>

#include "log.hpp"

namespace gfx::vk
{
	gfx::renderer create_vulkan_renderer(ui::vulkan_context &context) noexcept
	{
		return gfx::renderer(std::make_unique<detail::vulkan_renderer_core>(context));
	}
}

namespace gfx::vk::detail
{
	vulkan_renderer_core::vulkan_renderer_core([[maybe_unused]]ui::vulkan_context &context) noexcept
	{
		LOG_CRITICAL("IMPLEMENT ME!");
	}

	void vulkan_renderer_core::set_viewport([[maybe_unused]] const glm::ivec2 &p, [[maybe_unused]] const glm::ivec2 &size) noexcept
	{
		LOG_CRITICAL("IMPLEMENT ME!");
	}

	void vulkan_renderer_core::set_clear_color([[maybe_unused]] float r, [[maybe_unused]] float g, [[maybe_unused]] float b, [[maybe_unused]] float a) noexcept
	{
		LOG_CRITICAL("IMPLEMENT ME!");
	}

	void vulkan_renderer_core::clear_color() noexcept
	{
		LOG_CRITICAL("IMPLEMENT ME!");
	}

	void vulkan_renderer_core::clear_depth() noexcept
	{
		LOG_CRITICAL("IMPLEMENT ME!");
	}

	gfx::buffer vulkan_renderer_core::create_buffer([[maybe_unused]] gfx::buffer_type type, [[maybe_unused]] gfx::usage_hint hint, [[maybe_unused]] const void *data, [[maybe_unused]] size_t size)
	{
		LOG_CRITICAL("IMPLEMENT ME!");
		return {};
	}

	gfx::program vulkan_renderer_core::create_program([[maybe_unused]] gfx::program_type type, [[maybe_unused]] const fs::path &file_path)
	{
		LOG_CRITICAL("IMPLEMENT ME!");
		return {};
	}

	gfx::pipeline vulkan_renderer_core::create_pipeline()
	{
		LOG_CRITICAL("IMPLEMENT ME!");
		return {};
	}

	gfx::mesh vulkan_renderer_core::create_mesh([[maybe_unused]] const std::initializer_list<buffer_description> &descriptions)
	{
		LOG_CRITICAL("IMPLEMENT ME!");
		return {};
	}

	std::unique_ptr<gfx::imgui::imgui_graphics_core> vulkan_renderer_core::create_imgui_graphics_core()
	{
		LOG_CRITICAL("IMPLEMENT ME!");
		return {};
	}

	void vulkan_renderer_core::use_pipeline([[maybe_unused]] gfx::pipeline &pipeline)
	{
		LOG_CRITICAL("IMPLEMENT ME!");
	}

	void vulkan_renderer_core::draw_indexed_mesh([[maybe_unused]] const gfx::mesh &m, [[maybe_unused]] gfx::draw_mode mode, [[maybe_unused]] gfx::index_type type, [[maybe_unused]] size_t start, [[maybe_unused]] size_t count)
	{
		LOG_CRITICAL("IMPLEMENT ME!");
	}

	const ::vk::RenderPass &vulkan_renderer_core::get_render_pass() const
	{
		return render_pass.get();
	}

	const ::vk::CommandBuffer &vulkan_renderer_core::get_current_command_buffer() const
	{
		return command_buffer.get();
	}
}

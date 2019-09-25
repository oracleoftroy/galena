#pragma once

#include <gfx/renderer.hpp>
#include <vulkan/vulkan.hpp>

namespace ui { class vulkan_context; }

namespace gfx::vk::detail
{
	class vulkan_renderer_core final : public gfx::renderer_core
	{
	public:
		explicit vulkan_renderer_core(ui::vulkan_context &context) noexcept;

		void set_viewport(const glm::ivec2 &p, const glm::ivec2 &size) noexcept override;
		void set_clear_color(float r, float g, float b, float a) noexcept override;
		void clear_color() noexcept override;
		void clear_depth() noexcept override;

		gfx::buffer create_buffer(gfx::buffer_type type, gfx::usage_hint hint, const void *data, size_t size) override;
		gfx::program create_program(gfx::program_type type, const fs::path &file_path) override;
		gfx::pipeline create_pipeline() override;
		gfx::mesh create_mesh(const std::initializer_list<buffer_description> &descriptions) override;
		std::unique_ptr<gfx::imgui::imgui_graphics_core> create_imgui_graphics_core() override;

		void use_pipeline(gfx::pipeline &pipeline) override;
		void draw_indexed_mesh(const gfx::mesh &m, gfx::draw_mode mode, gfx::index_type type, size_t start, size_t count) override;

		// TODO: consider avoiding the getters. They are used by imgui. We could easily construct imgui with the render pass, but we need the correct command buffer every frame
		const ::vk::RenderPass &get_render_pass() const;
		const ::vk::CommandBuffer &get_current_command_buffer() const;

	private:

		::vk::UniqueRenderPass render_pass;
		::vk::UniqueCommandBuffer command_buffer;
	};
}

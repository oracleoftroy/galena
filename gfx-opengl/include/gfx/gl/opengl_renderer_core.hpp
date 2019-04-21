#pragma once

#include <memory>
#include <glm/glm.hpp>

namespace gfx { class renderer; }
namespace gfx::imgui { class imgui_graphics_core; }
namespace ui { class opengl_context; }

namespace gfx::gl
{
	renderer create_opengl_renderer(ui::opengl_context &context) noexcept;

	namespace detail
	{
		class opengl_renderer_core;
		void core_set_viewport(opengl_renderer_core &core, const glm::ivec2 &p, const glm::ivec2 &size) noexcept;
		void core_set_clear_color(opengl_renderer_core &core, float r, float g, float b, float a) noexcept;
		void core_clear_color(opengl_renderer_core &core) noexcept;

		std::unique_ptr<imgui::imgui_graphics_core> core_create_imgui_graphics_core(opengl_renderer_core &core) noexcept;
	}
}

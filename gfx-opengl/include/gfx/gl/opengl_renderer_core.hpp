#pragma once

#include <memory>
#include <glm/glm.hpp>

namespace gfx
{
	template <typename core, typename deleter>
	class renderer;

	namespace imgui
	{
		class imgui_graphics_core;
	}
}

namespace ui
{
	class opengl_context;
}

namespace gfx::gl
{
	class opengl_renderer_core;

	struct opengl_renderer_core_deleter
	{
		void operator()(opengl_renderer_core *ptr) const;
	};

	using opengl_renderer = gfx::renderer<opengl_renderer_core, opengl_renderer_core_deleter>;
	opengl_renderer create_opengl_renderer(ui::opengl_context &context) noexcept;

	void do_set_viewport(opengl_renderer_core &core, const glm::ivec2 &p, const glm::ivec2 &size) noexcept;
	void do_set_clear_color(opengl_renderer_core &core, float r, float g, float b, float a) noexcept;
	void do_clear_color(opengl_renderer_core &core) noexcept;

	std::unique_ptr<imgui::imgui_graphics_core> do_create_imgui_graphics_core(opengl_renderer_core &core) noexcept;
}

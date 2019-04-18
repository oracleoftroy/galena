#pragma once

#include <memory>
#include <glm/glm.hpp>

namespace gfx
{
	namespace imgui
	{
		class imgui_graphics_core;
	}

	template <typename renderer_core, typename renderer_core_deleter = std::default_delete<renderer_core>>
	class renderer
	{
		using core_ptr = std::unique_ptr<renderer_core, renderer_core_deleter>;

	public:
		explicit renderer(core_ptr &&core) noexcept;

		void set_viewport(const glm::ivec2 &p, const glm::ivec2 &size) noexcept;
		void set_clear_color(float r, float g, float b, float a) noexcept;

		void clear_color() noexcept;

		std::unique_ptr<imgui::imgui_graphics_core> create_imgui_graphics_core() noexcept;

	private:
		core_ptr core;
	};

	template <typename core, typename deleter>
	renderer<core, deleter>::renderer(core_ptr &&core) noexcept
		: core(std::move(core))
	{
	}

	template <typename core, typename deleter>
	void renderer<core, deleter>::set_viewport(const glm::ivec2 &p, const glm::ivec2 &size) noexcept
	{
		do_set_viewport(*core, p, size);
	}

	template <typename core, typename deleter>
	void renderer<core, deleter>::set_clear_color(float r, float g, float b, float a) noexcept
	{
		do_set_clear_color(*core, r, g, b, a);
	}

	template <typename core, typename deleter>
	void renderer<core, deleter>::clear_color() noexcept
	{
		do_clear_color(*core);
	}

	template <typename core, typename deleter>
	std::unique_ptr<imgui::imgui_graphics_core> renderer<core, deleter>::create_imgui_graphics_core() noexcept
	{
		return do_create_imgui_graphics_core(*core);
	}
}

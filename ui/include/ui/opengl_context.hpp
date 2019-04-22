#pragma once

#include <memory>
#include <glm/glm.hpp>

namespace ui
{
	using opengl_load_proc = void *(*)(const char *);
	class window;
	namespace imgui { class imgui_system; }

	class opengl_context
	{
	public:
		~opengl_context() noexcept;

		opengl_load_proc get_load_proc() const noexcept;
		bool supports_extension(const char *name) const noexcept;
		glm::ivec2 drawable_size() const noexcept;

		int swap_interval() const noexcept;

		// controls the swap interval
		// 0 - disable vsync, possibly causing tearing
		// positive N: render every Nth vsync. If the target vsync is missed, renders on the next vsync
		// negative N: render every abs(N)th vsync. If the target vsync is missed, renders immediately, possibly causing tearing.
		// see: *_EXT_swap_control / *_EXT_swap_control_tear
		bool set_swap_interval(int interval) noexcept;

		void make_current() noexcept;
		void present() noexcept;

	public:
		opengl_context(opengl_context &&other) noexcept = default;
		opengl_context &operator=(opengl_context &&other) = default;

		opengl_context(const opengl_context &) noexcept = delete;
		opengl_context &operator=(const opengl_context &) = delete;

	private:
		class opengl_context_data;
		friend class window;
		friend class imgui::imgui_system;
		std::unique_ptr<opengl_context_data> data;

	private:
		opengl_context(std::unique_ptr<opengl_context_data> &&data);
	};
}

#pragma once

#include <memory>

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
		void make_current() noexcept;
		void present() noexcept;

	public:
		opengl_context(opengl_context &&) noexcept = default;
		opengl_context &operator=(opengl_context &&) = default;

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

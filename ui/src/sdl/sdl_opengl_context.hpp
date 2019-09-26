#pragma once

#include <ui/opengl_context.hpp>

struct SDL_Window;
using SDL_GLContext = void *;

namespace ui
{
	namespace imgui
	{
		class imgui_system;
	}

	class opengl_context::opengl_context_data
	{
	public:
		opengl_context_data(SDL_Window *window, SDL_GLContext context) noexcept;
		~opengl_context_data();

		glm::ivec2 drawable_size() const noexcept;
		void make_current();
		void present() noexcept;

	private:
		friend class imgui::imgui_system;
		SDL_Window *window;
		SDL_GLContext context;
	};
}

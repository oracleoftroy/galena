#pragma once

#include <ui/opengl_context.hpp>

#include <SDL2/SDL.h>

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
		~opengl_context_data() noexcept;

		void make_current();
		void present() noexcept;

	private:
		friend class imgui::imgui_system;
		SDL_Window *window;
		SDL_GLContext context;
	};
}

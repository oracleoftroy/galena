#include "sdl_opengl_context.hpp"

#include "../platform_info.hpp"
#if UI_PLATFORM == UI_PLATFORM_IMPL_SDL

#include "../log.hpp"
#include "sdl_util.hpp"

namespace ui
{
	opengl_load_proc opengl_context::get_load_proc() const noexcept
	{
		return SDL_GL_GetProcAddress;
	}

	opengl_context::opengl_context_data::opengl_context_data(SDL_Window *window, SDL_GLContext context) noexcept
		: window(window), context(context)
	{
	}

	opengl_context::opengl_context_data::~opengl_context_data() noexcept
	{
		SDL_GL_DeleteContext(context);
	}

	void opengl_context::opengl_context_data::make_current()
	{
		LOG_DEBUG("Setting the active OpenGL context");
		SDL_VERIFY(!SDL_GL_MakeCurrent(window, context));
	}

	void opengl_context::opengl_context_data::present() noexcept
	{
		SDL_GL_SwapWindow(window);
	}

}

#endif // UI_PLATFORM == UI_PLATFORM_IMPL_SDL

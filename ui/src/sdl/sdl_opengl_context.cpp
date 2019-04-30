#include "sdl_opengl_context.hpp"

#include "../log.hpp"
#include "sdl_util.hpp"

namespace ui
{
	opengl_context::opengl_context_data::opengl_context_data(SDL_Window *window, SDL_GLContext context) noexcept
		: window(window), context(context)
	{
	}

	opengl_context::opengl_context_data::~opengl_context_data()
	{
		SDL_GL_DeleteContext(context);
	}

	opengl_load_proc opengl_context::get_load_proc() const noexcept
	{
		return SDL_GL_GetProcAddress;
	}

	bool opengl_context::supports_extension(const char *name) const noexcept
	{
		return SDL_GL_ExtensionSupported(name);
	}

	glm::ivec2 opengl_context::opengl_context_data::drawable_size() const noexcept
	{
		int w, h;
		SDL_GL_GetDrawableSize(window, &w, &h);
		return {w, h};
	}

	int opengl_context::swap_interval() const noexcept
	{
		return SDL_GL_GetSwapInterval();
	}

	bool opengl_context::set_swap_interval(int interval) noexcept
	{
		return SDL_GL_SetSwapInterval(interval) == 0;
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

#pragma once

#include <stdexcept>
#include <SDL2/SDL.h>
#include <ui/platform.hpp>
#include <ui/window.hpp>

// log and throw sdl exceptions, this is a macro so that the logger will pick up the correct source file and line number
#define SDL_THROW() do { LOG_ERROR("SDL error: {0}", SDL_GetError()); throw sdl::sdl_exception(); } while (false)

// logs and throws sdl exception if the condition fails
#define SDL_VERIFY(x) do { if (!(x)) SDL_THROW(); } while (false)

// log a warning if the condition fails, but allows code to continue
#define SDL_REPORT(x) do { if (!(x)) LOG_WARN("{0}", SDL_GetError()); } while (false)

namespace ui::sdl
{
	struct sdl_exception : public std::runtime_error
	{
		sdl_exception() : std::runtime_error(SDL_GetError()) {}
	};

	constexpr Uint32 to_sdl(window_mode mode) noexcept
	{
		// the initial state of our window - TODO: are there other flags we want to support?
		return mode == window_mode::fullscreen ? SDL_WINDOW_FULLSCREEN | SDL_WINDOW_BORDERLESS
			: mode == window_mode::fullscreen_borderless ? SDL_WINDOW_FULLSCREEN_DESKTOP
			: 0;
	}

	constexpr Uint32 to_sdl(gfx_engine engine) noexcept
	{
		// opengl and vulkan for SDL need a special flag during window creation to load the proper library, whereas directx just needs the hwnd
		return engine == gfx_engine::vulkan ? SDL_WINDOW_VULKAN
			: engine == gfx_engine::opengl ? SDL_WINDOW_OPENGL
			: 0;
	}

	constexpr Uint32 to_sdl(window_mode flags, gfx_engine engine) noexcept
	{
		// default flags - always enabling high dpi seems like a good idea to prevent the window manager from trying to scale our app
		return SDL_WINDOW_ALLOW_HIGHDPI | to_sdl(flags) | to_sdl(engine);
	}
}

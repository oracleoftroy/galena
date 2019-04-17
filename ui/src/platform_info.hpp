#pragma once

#define UI_PLATFORM_IMPL_SDL 1

#if !defined(PLATFORM_IMPL)
#define UI_PLATFORM UI_PLATFORM_IMPL_SDL
#endif

#if UI_PLATFORM == UI_PLATFORM_IMPL_SDL
#define UI_PLATFORM_H "sdl/sdl_platform.hpp"
//#define UI_WINDOW_H "sdl/sdl_window.hpp"
#define UI_OPENGL_CONTEXT_H "sdl/sdl_opengl_context.hpp"
#define UI_IMGUI_SYSYEM_H "sdl/sdl_imgui_system.hpp"
#endif

#include "sdl_platform.hpp"

#include <string_view>
#include <utility>

#if defined __clang__
#	pragma GCC diagnostic push
#	pragma GCC diagnostic ignored "-Wpragma-pack"
#endif

#include <SDL2/SDL.h>

#if defined __clang__
#	pragma GCC diagnostic pop
#endif

#include <ui/events.hpp>
#include <ui/window.hpp>

#include "../log.hpp"
#include "sdl_util.hpp"
#include "sdl_dispatch_events.hpp"

using namespace std::string_view_literals;

namespace ui
{
	namespace imgui
	{
		bool imgui_dispatch_events(SDL_Event *event) noexcept;
	}

	namespace
	{
		static void SDLCALL sdl_log_function(void *userdata, int category, SDL_LogPriority priority, const char *message) noexcept;
	}

	sdl_init::sdl_init() : sdl_logger(core::register_logger("SDL"))
	{
		LOG_INFO("Initializing SDL");

		sdl_logger->set_pattern("[%T] [%^%n%$] %v");
		SDL_LogSetOutputFunction(sdl_log_function, &sdl_logger);

		// TODO: do we want to set this? use default for now
		// our log levels start at 0 and SDL starts at 1, but are otherwise the same
		// SDL_LogSetAllPriority(SDL_LogPriority(LOG_LEVEL + 1));

		SDL_Init(SDL_INIT_EVERYTHING);
	}

	sdl_init::~sdl_init()
	{
		LOG_INFO("Destroying SDL");
		SDL_Quit();
	}

	window platform::platform_data::create_window(const std::string &title, int width, int height, window_mode flags, gfx_engine engine)
	{
		LOG_INFO("Creating main window");
		auto *handle = SDL_CreateWindow(title.data(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, sdl::to_sdl(flags, engine));
		SDL_VERIFY(handle);

		return window(handle);
	}

	void platform::platform_data::attach_event_listener(event_listener_type &&listener)
	{
		event_listener = std::move(listener);
	}

	bool platform::platform_data::dispatch_events() noexcept
	{
		if (!event_listener)
			LOG_WARN("dispatch events called without an attached listener");

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			bool imgui_handled = imgui::imgui_dispatch_events(&event);
			if (event.type == SDL_QUIT)
				return false;
			else if (event_listener && !imgui_handled)
				sdl::dispatch_events(event_listener, event);
		}

		return true;
	}

	namespace
	{
		static constexpr std::string_view from_category(int category) noexcept
		{
			return category == SDL_LOG_CATEGORY_APPLICATION ? "APPLICATION"sv
				: category == SDL_LOG_CATEGORY_ERROR ? "ERROR"sv
				: category == SDL_LOG_CATEGORY_ASSERT ? "ASSERT"sv
				: category == SDL_LOG_CATEGORY_SYSTEM ? "SYSTEM"sv
				: category == SDL_LOG_CATEGORY_AUDIO ? "AUDIO"sv
				: category == SDL_LOG_CATEGORY_VIDEO ? "VIDEO"sv
				: category == SDL_LOG_CATEGORY_RENDER ? "RENDER"sv
				: category == SDL_LOG_CATEGORY_INPUT ? "INPUT"sv
				: category == SDL_LOG_CATEGORY_TEST ? "TEST"sv
				: "UNKNOWN"sv;
		}

		static constexpr spdlog::level::level_enum from_priority(SDL_LogPriority priority) noexcept
		{
			return priority == SDL_LOG_PRIORITY_VERBOSE ? spdlog::level::trace
				: priority == SDL_LOG_PRIORITY_DEBUG ? spdlog::level::debug
				: priority == SDL_LOG_PRIORITY_INFO ? spdlog::level::info
				: priority == SDL_LOG_PRIORITY_WARN ? spdlog::level::warn
				: priority == SDL_LOG_PRIORITY_ERROR ? spdlog::level::err
				: spdlog::level::critical;
		}

		static void SDLCALL sdl_log_function(void *userdata, int category, SDL_LogPriority priority, const char *message) noexcept
		{
			auto *logger = static_cast<core::logger *>(userdata);
			(*logger)->log(from_priority(priority), "({0}): {1}", from_category(category), message);
		}
	}
}

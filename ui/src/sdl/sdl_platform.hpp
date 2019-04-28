#pragma once

#include <ui/platform.hpp>
#include <core/log_subsystem.hpp>

struct ImGuiContext;

namespace ui
{
	class sdl_init
	{
	public:
		sdl_init();
		~sdl_init();

	private:
		core::logger sdl_logger;
	};

	class platform::platform_data
	{
	public:
		void attach_event_listener(event_listener_type &&listener);
		bool dispatch_events() noexcept;

	private:
		sdl_init sdl;
		event_listener_type event_listener;
	};
}

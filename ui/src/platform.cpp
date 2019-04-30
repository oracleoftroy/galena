#include <ui/platform.hpp>

#include <utility>
#include <ui/window.hpp>
#include "log.hpp"
#include "platform_info.hpp"
#include UI_PLATFORM_H

namespace ui
{
	platform platform::create()
	{
		return platform(std::make_unique<platform::platform_data>());
	}

	platform::platform(std::unique_ptr<platform_data> &&data) noexcept
		: data(std::move(data))
	{
	}

	// theoretically, only the destructor needs to be here, but MSVC thinks that platform_data is incomplete unless all of these are here.
	platform::platform() noexcept = default;
	platform::~platform() = default;
	platform::platform(platform &&other) noexcept = default;
	platform &platform::operator=(platform &&other) noexcept = default;

	void platform::attach_event_listener(event_listener_type event_listener)
	{
		data->attach_event_listener(std::move(event_listener));
	}

	bool platform::dispatch_events() noexcept
	{
		return data->dispatch_events();
	}

	window platform::create_window(const std::string &title, int width, int height, window_mode flags, gfx_engine engine)
	{
		return data->create_window(title, width, height, flags, engine);
	}
}

#include <ui/platform.hpp>

#include "log.hpp"

#include "platform_info.hpp"
#include UI_PLATFORM_H

#include <utility>

namespace ui
{
	platform::platform() noexcept
		: data(std::make_unique<platform::platform_data>())
	{
	}

	platform::platform(std::unique_ptr<platform_data> &&data) noexcept
		: data(std::move(data))
	{
	}

	platform::~platform() = default;

	void platform::attach_event_listener(event_listener_type event_listener)
	{
		data->attach_event_listener(std::move(event_listener));
	}

	bool platform::dispatch_events() noexcept
	{
		return data->dispatch_events();
	}
}

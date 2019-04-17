#include <ui/platform.hpp>

#include "log.hpp"

#include "platform_info.hpp"
#include UI_PLATFORM_H

namespace ui
{
	platform platform::create()
	{
		LOG_INFO("Creating platform");
		return platform(std::make_unique<platform::platform_data>());
	}

	platform::platform(std::unique_ptr<platform_data> &&data) noexcept
		: data(std::move(data))
	{
	}

	platform::~platform() noexcept = default;

	void platform::attach_event_listener(event_listener_type event_listener)
	{
		data->attach_event_listener(std::move(event_listener));
	}

	bool platform::dispatch_events() noexcept
	{
		return data->dispatch_events();
	}
}

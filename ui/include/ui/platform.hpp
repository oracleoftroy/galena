#pragma once

#include <functional>
#include <memory>
#include <string>

namespace ui
{
	class event;
	class window;
	enum class window_mode;

	enum class gfx_engine
	{
		none,
		directx,
		opengl,
		vulkan
	};

	class platform final
	{
	public:
		[[nodiscard]] static platform create();

		~platform() noexcept;

		using event_listener_type = std::function<void(const event &)>;
		void attach_event_listener(event_listener_type event_listener);
		[[nodiscard]] window create_window(const std::string &title, int width, int height, window_mode flags, gfx_engine engine = gfx_engine::none);
		[[nodiscard]] bool dispatch_events() noexcept;

	public:
		platform(platform &&other) noexcept = default;
		platform &operator=(platform &&other) noexcept = default;
		platform(const platform &other) noexcept = delete;
		platform &operator=(const platform &other) noexcept = delete;

	private:
		class platform_data;
		platform(std::unique_ptr<platform_data> &&data) noexcept;

		std::unique_ptr<platform_data> data;
	};
}

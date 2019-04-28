#pragma once

#include <glm/glm.hpp>

namespace ui
{
	class platform;
	struct config_opengl;
	class opengl_context;

	enum class window_mode
	{
		// creates a window at the specified width and height
		windowed,

		// changes resolution to specified width and height and creates a fullscreen window at matching resolution
		fullscreen,

		// creates a window that matches the current desktop resolution, width and height ignored
		fullscreen_borderless,
	};

	class window final
	{
	public:
		window() noexcept = default;
		~window();

		[[nodiscard]] glm::ivec2 size() const noexcept;

	public:
		// create a context for opengl based on the provided config.
		// on return, the config will have the actual configuration that was created
		// which should be at least as good as the desired configuration
		[[nodiscard]] opengl_context opengl_create_context(config_opengl &desired);

	public:
		window(window &&other) noexcept;
		window &operator=(window &&other) noexcept;

		window(const window &other) noexcept = delete;
		window &operator=(const window &other) noexcept = delete;

	private:
		friend class ::ui::platform;
		explicit window(void *handle) noexcept;

	private:
		void *handle = nullptr;
	};
}

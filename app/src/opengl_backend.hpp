#pragma once

#include <string>
#include <glm/glm.hpp>

#include <ui/opengl_context.hpp>
#include <ui/window.hpp>

namespace ui
{
	struct config_opengl;
	class platform;
}

namespace gfx
{
	class renderer;
}

namespace app
{
	template <typename>
	class imgui;

	using imgui_opengl = imgui<ui::opengl_context>;

	class opengl_backend final
	{
	public:
		[[nodiscard]] static opengl_backend create(ui::platform &platform, const std::string &title, int width, int height, ui::window_mode flags);
		opengl_backend() noexcept = default;

		gfx::renderer create_renderer() noexcept;
		imgui_opengl create_imgui(gfx::renderer &renderer) noexcept;

		glm::ivec2 drawable_size() const noexcept;
		ui::opengl_context &get_context() noexcept;

		void present() noexcept;

	private:
		opengl_backend(ui::window &&window, ui::opengl_context &&context) noexcept;

		ui::window window;
		ui::opengl_context context;
	};
}

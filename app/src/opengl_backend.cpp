#include "opengl_backend.hpp"

#include <utility>

#include <gfx/renderer.hpp>
#include <gfx/gl/opengl_renderer_core.hpp>
#include <ui/config_opengl.hpp>
#include <ui/platform.hpp>
#include "imgui.hpp"

namespace app
{
	opengl_backend opengl_backend::create(ui::platform &platform, const std::string &title, int width, int height, ui::window_mode flags)
	{
		ui::config_opengl config{ui::opengl_profile::es, 3, 2};

		auto window = platform.create_window(title, width, height, flags, ui::gfx_engine::opengl);
		auto context = window.opengl_create_context(config);

		return {std::move(window), std::move(context)};
	}

	opengl_backend::opengl_backend(ui::window &&window, ui::opengl_context &&context) noexcept
		: window(std::move(window)), context(std::move(context))
	{
	}

	gfx::renderer opengl_backend::create_renderer() noexcept
	{
		return gfx::gl::create_opengl_renderer(context);
	}

	imgui_opengl opengl_backend::create_imgui(gfx::renderer &renderer) noexcept
	{
		return app::imgui(context, renderer);
	}

	glm::ivec2 opengl_backend::drawable_size() const noexcept
	{
		return context.drawable_size();
	}

	ui::opengl_context &opengl_backend::get_context() noexcept
	{
		return context;
	}

	void opengl_backend::present() noexcept
	{
		context.present();
	}
}

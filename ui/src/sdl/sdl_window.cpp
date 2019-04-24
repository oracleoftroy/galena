#include <ui/window.hpp>

#include "../platform_info.hpp"
#if UI_PLATFORM == UI_PLATFORM_IMPL_SDL

#include <type_traits>
#include <SDL2/SDL.h>
#include <ui/config_opengl.hpp>
#include <ui/opengl_context.hpp>

#include "../log.hpp"
#include "sdl_util.hpp"
#include "sdl_opengl_context.hpp"

#define WINDOW static_cast<SDL_Window*>(handle)

namespace ui
{
	namespace
	{
		static void read_opengl_config(config_opengl &cfg) noexcept;
	}

	window::~window() noexcept
	{
		LOG_INFO("Destroying window");
		SDL_DestroyWindow(WINDOW);
	}

	glm::ivec2 window::size() const noexcept
	{
		int w, h;
		SDL_GetWindowSize(WINDOW, &w, &h);
		return {w, h};
	}

	opengl_context window::opengl_create_context(config_opengl &cfg)
	{
		auto profile = [](auto p)
		{
			using namespace std::string_view_literals;
			return p == gl_context_profile::core ? "GL Core"sv
				: p == gl_context_profile::compatibility ? "GL Compatibility"sv
				: p == gl_context_profile::es ? "GLES"sv
				: "<unknown>"sv;
		};

		LOG_INFO("requesting opengl context for {0} {1}.{2}", profile(cfg.context_profile), cfg.context_major_version, cfg.context_minor_version);

		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, static_cast<int>(cfg.context_profile)));
		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, cfg.context_major_version));
		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, cfg.context_minor_version));
		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, static_cast<int>(cfg.context_flags)));
		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_CONTEXT_RELEASE_BEHAVIOR, static_cast<int>(cfg.context_release_behavior)));

		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_RED_SIZE, cfg.red_size));
		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, cfg.green_size));
		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, cfg.blue_size));
		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, cfg.alpha_size));

		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, cfg.buffer_size));
		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, cfg.depth_size));
		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, cfg.stencil_size));

		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, cfg.enable_msaa));
		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, cfg.msaa_samples));

		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE, cfg.accum_red_size));
		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE, cfg.accum_green_size));
		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE, cfg.accum_blue_size));
		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE, cfg.accum_alpha_size));

		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, cfg.double_buffer));
		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, cfg.accelerated_visual));
		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_STEREO, cfg.stereo));
		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, cfg.share_with_current_context));
		SDL_REPORT(!SDL_GL_SetAttribute(SDL_GL_FRAMEBUFFER_SRGB_CAPABLE, cfg.framebuffer_srgb_capable));

		SDL_GLContext context = SDL_GL_CreateContext(WINDOW);
		SDL_REPORT(context);

		read_opengl_config(cfg);

		if (context)
		{
			LOG_INFO("created opengl context for {0} {1}.{2}", profile(cfg.context_profile), cfg.context_major_version, cfg.context_minor_version);
			return {std::make_unique<opengl_context::opengl_context_data>(WINDOW, context)};
		}

		return {};
	}

	namespace
	{
		static void read_opengl_config(config_opengl &cfg) noexcept
		{
			// savely read boolean values
			auto SDL_GL_GetAttributeB = [](SDL_GLattr field, bool *value)
			{
				int b;
				int ret = SDL_GL_GetAttribute(field, &b);
				*value = !!b;
				return ret;
			};

			// safely read enum value: should error if the enum's underlying type isn't an int
			auto SDL_GL_GetAttributeE = [](SDL_GLattr field, auto * value)
			{
				using type = std::underlying_type_t<std::remove_pointer_t<decltype(value)>>;
				static_assert(std::is_same_v<int, type>);

				return SDL_GL_GetAttribute(field, reinterpret_cast<type *>(value));
			};

			SDL_REPORT(!SDL_GL_GetAttributeE(SDL_GL_CONTEXT_PROFILE_MASK, &cfg.context_profile));
			SDL_REPORT(!SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &cfg.context_major_version));
			SDL_REPORT(!SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &cfg.context_minor_version));
			SDL_REPORT(!SDL_GL_GetAttributeE(SDL_GL_CONTEXT_FLAGS, &cfg.context_flags));
			SDL_REPORT(!SDL_GL_GetAttributeE(SDL_GL_CONTEXT_RELEASE_BEHAVIOR, &cfg.context_release_behavior));

			SDL_REPORT(!SDL_GL_GetAttribute(SDL_GL_RED_SIZE, &cfg.red_size));
			SDL_REPORT(!SDL_GL_GetAttribute(SDL_GL_GREEN_SIZE, &cfg.green_size));
			SDL_REPORT(!SDL_GL_GetAttribute(SDL_GL_BLUE_SIZE, &cfg.blue_size));
			SDL_REPORT(!SDL_GL_GetAttribute(SDL_GL_ALPHA_SIZE, &cfg.alpha_size));

			SDL_REPORT(!SDL_GL_GetAttribute(SDL_GL_BUFFER_SIZE, &cfg.buffer_size));
			SDL_REPORT(!SDL_GL_GetAttribute(SDL_GL_DEPTH_SIZE, &cfg.depth_size));
			SDL_REPORT(!SDL_GL_GetAttribute(SDL_GL_STENCIL_SIZE, &cfg.stencil_size));

			SDL_REPORT(!SDL_GL_GetAttributeB(SDL_GL_MULTISAMPLEBUFFERS, &cfg.enable_msaa));
			SDL_REPORT(!SDL_GL_GetAttribute(SDL_GL_MULTISAMPLESAMPLES, &cfg.msaa_samples));

			SDL_REPORT(!SDL_GL_GetAttribute(SDL_GL_ACCUM_RED_SIZE, &cfg.accum_red_size));
			SDL_REPORT(!SDL_GL_GetAttribute(SDL_GL_ACCUM_GREEN_SIZE, &cfg.accum_green_size));
			SDL_REPORT(!SDL_GL_GetAttribute(SDL_GL_ACCUM_BLUE_SIZE, &cfg.accum_blue_size));
			SDL_REPORT(!SDL_GL_GetAttribute(SDL_GL_ACCUM_ALPHA_SIZE, &cfg.accum_alpha_size));

			SDL_REPORT(!SDL_GL_GetAttributeB(SDL_GL_DOUBLEBUFFER, &cfg.double_buffer));
			SDL_REPORT(!SDL_GL_GetAttributeB(SDL_GL_ACCELERATED_VISUAL, &cfg.accelerated_visual));
			SDL_REPORT(!SDL_GL_GetAttributeB(SDL_GL_STEREO, &cfg.stereo));
			SDL_REPORT(!SDL_GL_GetAttributeB(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, &cfg.share_with_current_context));
			SDL_REPORT(!SDL_GL_GetAttributeB(SDL_GL_FRAMEBUFFER_SRGB_CAPABLE, &cfg.framebuffer_srgb_capable));
		}
	}
}

#endif // UI_PLATFORM == UI_PLATFORM_IMPL_SDL

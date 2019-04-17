#pragma once

#include <core/enum_util.hpp>

namespace ui
{
	enum class gl_context_profile : int
	{
		core = 0x01,
		compatibility = 0x02,
		es = 0x04
	};

	enum class gl_context_flags : int
	{
		none = 0,
		debug = 0x01,
		forward_compatible = 0x02,
		robust_access = 0x04,
		reset_isolation = 0x08
	};

	CORE_MAKE_FLAG_ENUM(gl_context_flags);

	enum class gl_context_release_behavior : int
	{
		none,
		flush
	};

	struct config_opengl
	{
		gl_context_profile context_profile = gl_context_profile::core;
		int context_major_version = 3;
		int context_minor_version = 2;
		gl_context_flags context_flags = gl_context_flags::none;
		gl_context_release_behavior context_release_behavior = gl_context_release_behavior::none;

		int red_size = 8;
		int green_size = 8;
		int blue_size = 8;
		int alpha_size = 8;

		int buffer_size = 32;
		int depth_size = 24;
		int stencil_size = 8;

		bool enable_msaa = true;
		int msaa_samples = 4;

		int accum_red_size = 0;
		int accum_green_size = 0;
		int accum_blue_size = 0;
		int accum_alpha_size = 0;

		bool double_buffer = true;
		bool accelerated_visual = true;
		bool stereo = false;
		bool share_with_current_context = false;
		bool framebuffer_srgb_capable = true;
		//context_reset_notification;
		//context_no_error
	};
}

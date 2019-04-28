#pragma once

#include <core/enum_util.hpp>

namespace ui
{
	enum class opengl_profile : int
	{
		core = 0x01,
		compatibility = 0x02,
		es = 0x04
	};

	enum class opengl_context_flags : int
	{
		none = 0,
		debug = 0x01,
		forward_compatible = 0x02,
		robust_access = 0x04,
		reset_isolation = 0x08
	};

	CORE_MAKE_FLAG_ENUM(opengl_context_flags);

	enum class opengl_release_behavior : int
	{
		none,
		flush
	};

	struct config_opengl
	{
		config_opengl() noexcept = default;
		config_opengl(opengl_profile profile, int major, int minor, opengl_context_flags flags = opengl_context_flags::none) noexcept;

		opengl_profile context_profile = opengl_profile::core;
		int major_version = 3;
		int minor_version = 2;
		opengl_context_flags context_flags = opengl_context_flags::none;
		opengl_release_behavior release_behavior = opengl_release_behavior::none;

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

	inline config_opengl::config_opengl(opengl_profile profile, int major, int minor, opengl_context_flags flags) noexcept
		: context_profile(profile), major_version(major), minor_version(minor), context_flags(flags)
	{
	}

#include <type_traits>

	static_assert(!std::is_trivial_v<config_opengl>);
	static_assert(std::is_trivially_copyable_v<config_opengl>);
	static_assert(std::is_standard_layout_v<config_opengl>);
	static_assert(!std::is_trivially_constructible_v<config_opengl>);
	static_assert(std::is_nothrow_constructible_v<config_opengl>);
	static_assert(!std::is_trivially_default_constructible_v<config_opengl>);
	static_assert(std::is_nothrow_default_constructible_v<config_opengl>);
	static_assert(std::is_trivially_copy_constructible_v<config_opengl>);
	static_assert(std::is_nothrow_copy_constructible_v<config_opengl>);
	static_assert(std::is_trivially_move_constructible_v<config_opengl>);
	static_assert(std::is_nothrow_move_constructible_v<config_opengl>);
	static_assert(std::is_trivially_copy_assignable_v<config_opengl>);
	static_assert(std::is_nothrow_copy_assignable_v<config_opengl>);
	static_assert(std::is_trivially_move_assignable_v<config_opengl>);
	static_assert(std::is_nothrow_move_assignable_v<config_opengl>);
	static_assert(std::is_trivially_destructible_v<config_opengl>);
	static_assert(std::is_nothrow_destructible_v<config_opengl>);
}

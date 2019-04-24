#pragma once

#include <cstdint>
#include <glm/glm.hpp>

#include <core/resource.hpp>

namespace gfx::gl
{
	enum class minify_filter
	{
		nearest,
		linear,
		nearest_mipmap_nearest,
		linear_mipmap_nearest,
		nearest_mipmap_linear,
		linear_mipmap_linear
	};

	enum class magnify_filter
	{
		nearest,
		linear,
	};

	enum class texture_wrap_mode
	{
		clamp_to_edge,
		mirrored_repeat,
		repeat,
		clamp_to_border
	};

	struct texture_wrap
	{
		texture_wrap(texture_wrap_mode mode) : s(mode), t(mode), r(mode) {}
		texture_wrap(texture_wrap_mode s, texture_wrap_mode t, texture_wrap_mode r = texture_wrap_mode::repeat) : s(s), t(t), r(r) {}

		texture_wrap_mode s, t, r;
	};

	enum class compare_mode
	{
		none,
		compare_ref_to_texture
	};

	enum class compare_function
	{
		less_than_equal,
		greater_than_equal,
		less,
		greater,
		equal,
		not_equal,
		always,
		never
	};

	class sampler final
	{
	public:
		static sampler create() noexcept;
		sampler() = default;

		void use_filter(minify_filter filter) noexcept;
		void use_filter(magnify_filter filter) noexcept;

		void min_lod(int lod) noexcept;
		void max_lod(int lod) noexcept;

		void wrap(texture_wrap wrap) noexcept;

		void use_compare_mode(compare_mode mode) noexcept;
		void use_compare_function(compare_function function) noexcept;

		void border_color(glm::vec4 color) noexcept;

	private:
		static uint32_t create_sampler() noexcept;
		static void destroy_sampler(uint32_t sampler) noexcept;
		CORE_GENERATE_RESOURCE(sampler_resource, uint32_t, create_sampler, destroy_sampler, core::resource::opts::implicit_conversion<true>);

		sampler(sampler_resource &&resource);

		friend class renderer;
		void unsafe_bind(int texture_unit) noexcept;

	private:
		sampler_resource resource;
	};
}

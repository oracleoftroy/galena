#pragma once

#include <cstdint>

#include <glm/glm.hpp>

#include <core/resource.hpp>

namespace gfx::gl
{
	enum class texture2d_target
	{
		texture_2d,
		texture_cube_map_positive_x,
		texture_cube_map_negative_x,
		texture_cube_map_positive_y,
		texture_cube_map_negative_y,
		texture_cube_map_positive_z,
		texture_cube_map_negative_z
	};

	enum class texture3d_target
	{
		texture_3d,
		texture_2d_array,
		texture_cube_map_array
	};

	enum class texture_format
	{
		red,
		red_integer,
		rg,
		rg_integer,
		rgb,
		rgb_integer,
		rgba,
		rgba_integer,
		depth_component,
		depth_stencil,
		stencil_index,
		luminance_alpha,
		luminance,
		alpha
	};

	enum class pixel_layout
	{
		uint8,
		int8,
		uint16,
		int16,
		uint32,
		int32,
		float16,
		float32,
		uint16_5_6_5,
		uint16_4_4_4_4,
		uint16_5_5_5_1,
		uint32_2_10_10_10_rev,
		uint32_10f_11f_11f_rev,
		uint32_5_9_9_9_rev,
		uint32_24_8,
		float32_uint32_24_8_rev
	};

	enum class row_alignment
	{
		uint8 = 1,
		uint16 = 2,
		uint32 = 4,
		uing64 = 8,
	};

	class image;

	class texture final
	{
	public:
		static texture create_from_image(const image &img, int level = 0);
		static texture create2d(texture2d_target target, const glm::ivec2 &size, texture_format format, pixel_layout layout, const void *data, row_alignment alignment, int level = 0, int stride = 0);
		static texture create3d(texture3d_target target, const glm::ivec3 &size, texture_format format, pixel_layout layout, const void *data, row_alignment alignment, int level = 0, int stride = 0);
		texture() = default;

	private:
		static uint32_t create_texture() noexcept;
		static void destroy_texture(uint32_t texture)noexcept;
		CORE_GENERATE_RESOURCE(texture_resource, uint32_t, create_texture, destroy_texture, core::resource::opts::implicit_conversion<true>);

		texture(uint32_t type, texture_resource &&tex) noexcept;

		uint32_t unsafe_bind() noexcept;

	private:
		friend class renderer;
		uint32_t type;
		texture_resource tex;
	};
}

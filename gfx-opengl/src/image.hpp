#pragma once

#include <glm/glm.hpp>

#include <cstdint>
#include <string>

#include <core/resource.hpp>

namespace gfx::gl
{
	class image final
	{
	public:
		static image create(const std::string &filename);
		static image create(const uint8_t *data, int width, int height, int num_channels);
		image() = default;

		glm::ivec2 size() const noexcept;
		int channels() const noexcept;
		const uint8_t *data() const noexcept;

	private:
		static uint8_t *load_image(const uint8_t *data, int width, int height, int num_channels) noexcept;
		static void destroy_image(uint8_t *image) noexcept;
		CORE_GENERATE_RESOURCE(image_resource, uint8_t*, load_image, destroy_image, core::resource::opts::implicit_conversion<true>);

		image(image_resource &&data, int width, int height, int num_channels);

	private:
		image_resource resource;
		int width, height, num_channels;
	};
}

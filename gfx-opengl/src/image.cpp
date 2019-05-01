//#pragma warning(disable: 4996) // disable warnings for std::copy/std::copy_n

#include "image.hpp"

#include <algorithm>
#include <cstdint>
#include <memory>
#include <string>
#include <utility>

#define STBI_FAILURE_USERMSG
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include "log.hpp"

namespace gfx::gl
{
	struct image_error final : public std::runtime_error
	{
		image_error(const std::string &what) : std::runtime_error(what)
		{
		}
	};

	image image::create(const std::string &filename)
	{
		using stbi_ptr = std::unique_ptr<stbi_uc, decltype(&stbi_image_free)>;
		int width, height, num_channels;
		stbi_ptr result(stbi_load(filename.c_str(), &width, &height, &num_channels, 0), stbi_image_free);

		if (!result)
		{
			auto msg = stbi_failure_reason();
			LOG_ERROR("Error loading image {0}: {1}", filename.c_str(), msg);
			throw image_error(msg);
		}

		auto resource = image_resource::create(result.get(), width, height, num_channels);
		return image(std::move(resource), width, height, num_channels);
	}

	image image::create(const uint8_t *data, int width, int height, int num_channels)
	{
		return image(image_resource::create(data, width, height, num_channels), width, height, num_channels);
	}

	image::image(image_resource &&resource, int width, int height, int num_channels)
		: resource(std::move(resource)), width(width), height(height), num_channels(num_channels)
	{
	}

	glm::ivec2 image::size() const noexcept
	{
		return {width, height};
	}

	int image::channels() const noexcept
	{
		return num_channels;
	}

	const uint8_t *image::data() const noexcept
	{
		return resource;
	}

	uint8_t *image::load_image(const uint8_t *data, int width, int height, int num_channels) noexcept
	{
		auto size = width * height * num_channels;
		auto buf = new uint8_t[size];

		std::copy_n(data, size, buf);

		return buf;
	}

	void image::destroy_image(uint8_t *image) noexcept
	{
		delete[] image;
	}
}

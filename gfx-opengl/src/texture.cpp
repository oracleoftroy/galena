#include "texture.hpp"

#include <utility>
#include <stdexcept>
#include <string>

#include <glad/glad.h>
#include "image.hpp"
#include "log.hpp"

namespace gfx::gl
{
	namespace
	{
		struct texture_error : public std::runtime_error
		{
			texture_error(const std::string &what) : std::runtime_error(what)
			{
			}
		};

		static constexpr GLenum texture2d_targets[] =
		{
			GL_TEXTURE_2D,
			GL_TEXTURE_CUBE_MAP_POSITIVE_X,
			GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
			GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
			GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
			GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
			GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
		};

		static constexpr GLenum texture3d_targets[] =
		{
			GL_TEXTURE_3D,
			GL_TEXTURE_2D_ARRAY,
			GL_TEXTURE_CUBE_MAP_ARRAY
		};

		static constexpr GLenum texture_formats[] =
		{
			GL_RED,
			GL_RED_INTEGER,
			GL_RG,
			GL_RG_INTEGER,
			GL_RGB,
			GL_RGB_INTEGER,
			GL_RGBA,
			GL_RGBA_INTEGER,
			GL_DEPTH_COMPONENT,
			GL_DEPTH_STENCIL,
			GL_STENCIL_INDEX,
			GL_LUMINANCE_ALPHA,
			GL_LUMINANCE,
			GL_ALPHA
		};

		static constexpr GLenum texture_pixel_formats[] =
		{
			GL_UNSIGNED_BYTE,
			GL_BYTE,
			GL_UNSIGNED_SHORT,
			GL_SHORT,
			GL_UNSIGNED_INT,
			GL_INT,
			GL_HALF_FLOAT,
			GL_FLOAT,
			GL_UNSIGNED_SHORT_5_6_5,
			GL_UNSIGNED_SHORT_4_4_4_4,
			GL_UNSIGNED_SHORT_5_5_5_1,
			GL_UNSIGNED_INT_2_10_10_10_REV,
			GL_UNSIGNED_INT_10F_11F_11F_REV,
			GL_UNSIGNED_INT_5_9_9_9_REV,
			GL_UNSIGNED_INT_24_8,
			GL_FLOAT_32_UNSIGNED_INT_24_8_REV
		};

		static constexpr GLenum to_gl(texture2d_target target)
		{
			return texture2d_targets[static_cast<size_t>(target)];
		}

		static constexpr GLenum to_gl(texture3d_target target)
		{
			return texture3d_targets[static_cast<size_t>(target)];
		}

		static constexpr GLenum to_gl(texture_format target)
		{
			return texture_formats[static_cast<size_t>(target)];
		}

		static constexpr GLenum to_gl(pixel_layout target)
		{
			return texture_pixel_formats[static_cast<size_t>(target)];
		}

		// TODO: see if we can more aggressibly request RGBA8 or GL_SRGB8_ALPHA8 formats always for rgb* types
		static GLint internal_format(texture_format format, pixel_layout layout)
		{
			if (format == texture_format::rgb && layout == pixel_layout::uint8)
				return GL_SRGB8;

			if (format == texture_format::rgb && layout == pixel_layout::uint16_5_6_5)
				return GL_RGB;

			if (format == texture_format::rgba && layout == pixel_layout::uint8)
				return GL_SRGB8_ALPHA8;

			if (format == texture_format::rgba && (layout == pixel_layout::uint16_4_4_4_4 || layout == pixel_layout::uint16_5_5_5_1))
				return GL_RGBA;

			if (format == texture_format::luminance_alpha && layout == pixel_layout::uint8)
				return GL_LUMINANCE_ALPHA;

			if (format == texture_format::luminance && layout == pixel_layout::uint8)
				return GL_LUMINANCE;

			if (format == texture_format::alpha && layout == pixel_layout::uint8)
				return GL_ALPHA;

			// TODO: support the full table of internal formats and remove this crap
			LOG_CRITICAL("Unsupported texture format ({0}) with pixel layout ({0})", (int)format, (int)layout);
			throw texture_error("Unsupported texture format");
		}
	}

	texture texture::create_from_image(const image &img, int level)
	{
		texture_format format;
		int bpp = img.channels();

		switch (bpp)
		{
		default:
			LOG_CRITICAL("Expecting image to have 1-4 components, it has {0}", bpp);
			throw texture_error("Expecting image to have 1-4 components");
		case 1:
			format = texture_format::luminance;
			break;
		case 2:
			format = texture_format::luminance_alpha;
			break;
		case 3:
			format = texture_format::rgb;
			break;
		case 4:
			format = texture_format::rgba;
			break;
		}

		return create2d(texture2d_target::texture_2d, img.size(), format, pixel_layout::uint8, img.data(), row_alignment::uint32, level);
	}

	texture texture::create2d(texture2d_target target, const glm::ivec2 &size, texture_format format, pixel_layout layout, const void *data, row_alignment alignment, int level, int stride)
	{
		auto resource = texture_resource::create();
		GLenum type = to_gl(target);
		glBindTexture(type, resource);
		glPixelStorei(GL_UNPACK_ALIGNMENT, static_cast<GLint>(alignment));
		glPixelStorei(GL_UNPACK_ROW_LENGTH, stride);

		glTexImage2D(type, level, internal_format(format, layout), size.x, size.y, 0, to_gl(format), to_gl(layout), data);
		glBindTexture(type, 0);
		return texture(type, std::move(resource));
	}

	texture texture::create3d(texture3d_target target, const glm::ivec3 &size, texture_format format, pixel_layout layout, const void *data, row_alignment alignment, int level, int stride)
	{
		auto resource = texture_resource::create();
		GLenum type = to_gl(target);
		glBindTexture(type, resource);
		glPixelStorei(GL_UNPACK_ALIGNMENT, static_cast<GLint>(alignment));
		glPixelStorei(GL_UNPACK_ROW_LENGTH, stride);

		glTexImage3D(type, level, internal_format(format, layout), size.x, size.y, size.z, 0, to_gl(format), to_gl(layout), data);
		glBindTexture(type, 0);
		return texture(type, std::move(resource));
	}

	texture::texture(uint32_t type, texture_resource &&tex) noexcept
		: type(type), tex(std::move(tex))
	{
	}

	uint32_t texture::unsafe_bind() noexcept
	{
		glBindTexture(type, tex);
		return type;
	}

	uint32_t texture::create_texture() noexcept
	{
		GLuint texture;
		glGenTextures(1, &texture);
		return texture;
	}

	void texture::destroy_texture(uint32_t texture) noexcept
	{
		glDeleteTextures(1, &texture);
	}
}

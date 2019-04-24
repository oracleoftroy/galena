#include "buffer.hpp"

#include <utility>
#include <glad/glad.h>

namespace gfx::gl
{
	namespace
	{
		static const GLenum binding_targets[] =
		{
			GL_ARRAY_BUFFER,
			GL_ELEMENT_ARRAY_BUFFER,
			GL_ATOMIC_COUNTER_BUFFER,
			GL_COPY_READ_BUFFER,
			GL_COPY_WRITE_BUFFER,
			GL_DISPATCH_INDIRECT_BUFFER,
			GL_DRAW_INDIRECT_BUFFER,
			GL_PIXEL_PACK_BUFFER,
			GL_PIXEL_UNPACK_BUFFER,
			GL_SHADER_STORAGE_BUFFER,
			GL_TEXTURE_BUFFER,
			GL_TRANSFORM_FEEDBACK_BUFFER,
			GL_UNIFORM_BUFFER
		};

		static const GLenum buffer_usages[] =
		{
			GL_STREAM_DRAW,
			GL_STATIC_DRAW,
			GL_DYNAMIC_DRAW,

			GL_STREAM_READ,
			GL_STATIC_READ,
			GL_DYNAMIC_READ,

			GL_STREAM_COPY,
			GL_STATIC_COPY,
			GL_DYNAMIC_COPY,
		};

		static constexpr GLenum to_gl(buffer_target target) noexcept
		{
			return binding_targets[static_cast<size_t>(target)];
		}

		static constexpr GLenum to_gl(buffer_usage usage) noexcept
		{
			return buffer_usages[static_cast<size_t>(usage)];
		}
	}

	buffer buffer::create(buffer_target target, buffer_usage usage, const void *data, size_t size) noexcept
	{
		auto resource = buffer_resource::create();

		glBindBuffer(to_gl(target), resource);
		glBufferData(to_gl(target), size, data, to_gl(usage));
		glBindBuffer(to_gl(target), 0);

		return buffer(std::move(resource));
	}
	
	buffer::buffer(buffer_resource &&buf) noexcept : buf(std::move(buf))
	{
	}

	uint32_t buffer::create_buffer() noexcept
	{
		GLuint buffer;
		glGenBuffers(1, &buffer);
		return 0;
	}

	void buffer::destroy_buffer(uint32_t buffer) noexcept
	{
		glDeleteBuffers(1, &buffer);
	}
}

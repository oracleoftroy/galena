#include "renderbuffer.hpp"

#include <cstddef>
#include <utility>
#include <glad/glad.h>

namespace gfx::gl
{
	namespace
	{
		constexpr GLenum renderbuffer_formats[] =
		{
			GL_RGB8,
			GL_RGBA8,
			GL_SRGB8_ALPHA8,
			
			GL_DEPTH_COMPONENT16,
			GL_DEPTH_COMPONENT24,
			GL_DEPTH_COMPONENT32F,
			GL_DEPTH24_STENCIL8,
			GL_DEPTH32F_STENCIL8,
			GL_STENCIL_INDEX8,
		};

		static constexpr GLenum to_gl(renderbuffer_format format) noexcept
		{
			return renderbuffer_formats[static_cast<size_t>(format)];
		}
	}

	renderbuffer renderbuffer::create(int width, int height, renderbuffer_format format) noexcept
	{
		auto buf = renderbuffer_resource::create();
		glBindRenderbuffer(GL_RENDERBUFFER, buf);
		glRenderbufferStorage(GL_RENDERBUFFER, to_gl(format), width, height);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);

		return renderbuffer(std::move(buf));
	}

	uint32_t renderbuffer::create_renderbuffer() noexcept
	{
		GLuint renderbuffer;
		glGenRenderbuffers(1, &renderbuffer);
		return renderbuffer;
	}

	void renderbuffer::destroy_renderbuffer(uint32_t renderbuffer) noexcept
	{
		glDeleteRenderbuffers(1, &renderbuffer);
	}

	renderbuffer::renderbuffer(renderbuffer_resource resource) noexcept
		: buffer(std::move(resource))
	{
	}

}

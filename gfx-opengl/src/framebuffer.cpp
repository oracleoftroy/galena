#include "framebuffer.hpp"

#include <cstddef>
#include <utility>
#include <glad/glad.h>
#include "renderbuffer.hpp"

namespace gfx::gl
{
	namespace
	{
		static constexpr GLenum framebuffer_targets[] =
		{
			GL_FRAMEBUFFER,
			GL_DRAW_FRAMEBUFFER,
			GL_READ_FRAMEBUFFER,
		};

		static constexpr GLenum framebuffer_attachments[] =
		{
			GL_DEPTH_ATTACHMENT,
			GL_STENCIL_ATTACHMENT,
			GL_DEPTH_STENCIL_ATTACHMENT,
		};

		static constexpr GLenum to_gl(framebuffer_target target) noexcept
		{
			return framebuffer_targets[static_cast<size_t>(target)];
		}

		static constexpr GLenum to_gl(framebuffer_attachment attachment) noexcept
		{
			return framebuffer_attachments[static_cast<size_t>(attachment)];
		}
	}

	uint32_t framebuffer::create_framebuffer() noexcept
	{
		GLuint buffer;
		glGenFramebuffers(1, &buffer);
		return buffer;
	}

	void framebuffer::destroy_framebuffer(uint32_t buffer) noexcept
	{
		glDeleteFramebuffers(1, &buffer);
	}

	framebuffer framebuffer::create() noexcept
	{
		return framebuffer(framebuffer_resource::create());
	}

	framebuffer::framebuffer(framebuffer_resource &&buf) noexcept
		: buffer(std::move(buf))
	{
	}

	void framebuffer::attach_color_buffer(framebuffer_target target, const renderbuffer &renderbuffer, int buffer_number) noexcept
	{
		unsafe_bind(target);
		glFramebufferRenderbuffer(to_gl(target), static_cast<GLenum>(GL_COLOR_ATTACHMENT0 + buffer_number), GL_RENDERBUFFER, renderbuffer.get_renderbuffer());
		unsafe_unbind(target);
	}

	void framebuffer::attach(framebuffer_target target, framebuffer_attachment attachment, const renderbuffer &renderbuffer) noexcept
	{
		unsafe_bind(target);
		glFramebufferRenderbuffer(to_gl(target), to_gl(attachment), GL_RENDERBUFFER, renderbuffer.get_renderbuffer());
		unsafe_unbind(target);
	}

	void framebuffer::invalidate_color_buffer(framebuffer_target target, int buffer_number) noexcept
	{
		unsafe_bind(target);
		GLenum gl_attachment = static_cast<GLenum>(GL_COLOR_ATTACHMENT0 + buffer_number);
		glInvalidateFramebuffer(to_gl(target), 1, &gl_attachment);
		unsafe_unbind(target);
	}

	void framebuffer::invalidate(framebuffer_target target, framebuffer_attachment attachment) noexcept
	{
		unsafe_bind(target);
		GLenum gl_attachment = to_gl(attachment);
		glInvalidateFramebuffer(to_gl(target), 1, &gl_attachment);
		unsafe_unbind(target);
	}

	void framebuffer::unsafe_bind(framebuffer_target target) noexcept
	{
		glBindFramebuffer(to_gl(target), buffer);
	}
	
	void framebuffer::unsafe_unbind(framebuffer_target target) noexcept
	{
		glBindFramebuffer(to_gl(target), 0);
	}
}

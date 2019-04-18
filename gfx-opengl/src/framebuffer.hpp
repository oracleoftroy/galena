#pragma once

#include <cstdint>
#include <core/resource.hpp>

namespace gfx::gl
{
	class renderbuffer;
	class renderer;

	enum class framebuffer_target
	{
		framebuffer,
		draw,
		read
	};

	enum class framebuffer_attachment
	{
		depth_attachment,
		stencil_attachment,
		depth_stencil_attachment,
	};

	class framebuffer final
	{
	public:
		static framebuffer create(renderer &renderer) noexcept;
		framebuffer() = default;

		void attach_color_buffer(framebuffer_target target, const renderbuffer &renderbuffer, int buffer_number = 0) noexcept;
		void attach(framebuffer_target target, framebuffer_attachment attachment, const renderbuffer &renderbuffer) noexcept;

		void invalidate_color_buffer(framebuffer_target target, int buffer_number = 0) noexcept;
		void invalidate(framebuffer_target target, framebuffer_attachment attachment) noexcept;

	private:
		static uint32_t create_framebuffer(renderer &renderer) noexcept;
		static void destroy_framebuffer(uint32_t buffer) noexcept;
		CORE_GENERATE_RESOURCE(framebuffer_resource, uint32_t, create_framebuffer, destroy_framebuffer, core::resource::opts::implicit_conversion<true>);
		
		explicit framebuffer(framebuffer_resource &&buf) noexcept;

	private:
		friend class renderer;
		void unsafe_bind(framebuffer_target target) noexcept;
		static void unsafe_unbind(framebuffer_target target) noexcept;

	private:
		framebuffer_resource buffer;
	};
}

#pragma once

#include <cstdint>
#include <core/resource.hpp>

namespace gfx::gl
{
	enum class renderbuffer_format
	{
		rgb8,
		rgba8,
		srgb8_alpha8,

		depth_component16,
		depth_component24,
		depth_component32f,
		depth24_stencil8,
		depth32f_stencil8,
		stencil_index8,
	};

	class renderbuffer final
	{
	public:
		static renderbuffer create(int width, int height, renderbuffer_format format) noexcept;
		renderbuffer() = default;

	private:
		static uint32_t create_renderbuffer() noexcept;
		static void destroy_renderbuffer(uint32_t buffer) noexcept;
		CORE_GENERATE_RESOURCE(renderbuffer_resource, uint32_t, create_renderbuffer, destroy_renderbuffer, core::resource::opts::implicit_conversion<true>);
		explicit renderbuffer(renderbuffer_resource resource) noexcept;

	private:
		friend class framebuffer;
		uint32_t get_renderbuffer() const { return buffer; }

	private:
		renderbuffer_resource buffer;
	};
}

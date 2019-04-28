#pragma once

#include <gfx/buffer.hpp>

#include "../buffer.hpp"

namespace gfx::gl::detail
{
	class opengl_buffer_core final : public gfx::buffer_core
	{
	public:
		static std::unique_ptr<opengl_buffer_core> create(buffer_type type, usage_hint hint, const void *data, size_t size);
		explicit opengl_buffer_core(gl::buffer &&buffer) noexcept;

		const gl::buffer &get() const;

	private:
		gl::buffer buffer;
	};
}

#include "opengl_buffer_core.hpp"
#include "../buffer.hpp"

namespace gfx::gl::detail
{
	opengl_buffer_core::opengl_buffer_core(gl::buffer &&buffer) noexcept
		: buffer(std::move(buffer))
	{
	}

	std::unique_ptr<opengl_buffer_core> opengl_buffer_core::create(buffer_type type, usage_hint hint, const void *data, size_t size)
	{
		// TODO: these exactly match for now so just cast, but as we extend this, make sure we maintain the proper relationship
		// TODO: think about how to force a compiler error should this assumption fail
		auto target = static_cast<buffer_target>(type);

		// TODO: grossly simplified usage, need to improve
		auto usage = hint == usage_hint::read_only ? buffer_usage::static_draw : buffer_usage::dynamic_draw;

		return std::make_unique<detail::opengl_buffer_core>(gl::buffer::create(target, usage, data, size));
	}

	const gl::buffer &opengl_buffer_core::get() const
	{
		return buffer;
	}
}

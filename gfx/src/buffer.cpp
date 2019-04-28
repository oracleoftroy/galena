#include <gfx/buffer.hpp>

#include <utility>

namespace gfx
{
	buffer::buffer(std::unique_ptr<buffer_core> &&core) noexcept
		: core(std::move(core))
	{
	}

	buffer_core &buffer::operator*()
	{
		return *core;
	}

	const buffer_core &buffer::operator*() const
	{
		return *core;
	}
}

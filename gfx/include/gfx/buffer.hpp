#pragma once

#include <memory>

namespace gfx
{
	enum class buffer_type
	{
		vertex,
		index,
	};

	enum class usage_hint
	{
		read_only,
		read_write
	};

	class buffer_core
	{
	public:
		virtual ~buffer_core() = default;
	};

	class buffer
	{
	public:
		buffer() noexcept = default;
		explicit buffer(std::unique_ptr<buffer_core> &&core) noexcept;

		buffer_core &operator*();
		const buffer_core &operator*() const;

	private:
		std::unique_ptr<buffer_core> core;
	};
}

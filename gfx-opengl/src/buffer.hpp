#pragma once

#include <cstdint>

#include "core/resource.hpp"

namespace gfx::gl
{
	enum class buffer_usage
	{
		stream_draw,
		static_draw,
		dynamic_draw,

		stream_read,
		static_read,
		dynamic_read,

		stream_copy,
		static_copy,
		dynamic_copy,
	};

	enum class buffer_target
	{
		vertex,
		index,

		// TODO: Much more to add
	};

	class renderer;
	class vertex_array_object;

	class buffer final
	{
	public:
		friend class vertex_array_object;
		static buffer create(renderer &renderer, buffer_target target, buffer_usage usage, const void *data, size_t size) noexcept;
		buffer() = default;

	private:
		static uint32_t create_buffer(renderer &renderer) noexcept;
		static void destroy_buffer(uint32_t buffer) noexcept;
		CORE_GENERATE_RESOURCE(buffer_resource, uint32_t, create_buffer, destroy_buffer, core::resource::opts::implicit_conversion<true>);

		explicit buffer(buffer_resource &&buf) noexcept;

		void bind_unsafe(buffer_target target) noexcept;
		static void unbind_unsafe(buffer_target target) noexcept;

	private:
		buffer_resource buf;
	};
}

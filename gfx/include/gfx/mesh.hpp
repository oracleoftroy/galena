#pragma once

#include <functional>
#include <initializer_list>
#include <memory>

namespace gfx
{
	class buffer;

	enum class component_type
	{
		int8,
		uint8,
		int16,
		uint16,
		int32,
		uint32,
		float32,
	};

	enum class index_type
	{
		uint8,
		uint16,
		uint32,
	};

	enum class draw_mode
	{
		points,
		lines,
		line_loop,
		line_strip,
		triangles,
		triangle_strip,
		triangle_fan,
	};

	struct buffer_index
	{
		buffer_index(uint32_t index, const buffer &buffer, size_t stride, size_t offset)
			: index(index), buffer(std::ref(buffer)), stride(stride), offset(offset)
		{
		}

		uint32_t index;
		std::reference_wrapper<const buffer> buffer;
		size_t stride;
		size_t offset;
	};

	struct buffer_description
	{
		buffer_description(uint32_t index, component_type type, int num_components, size_t offset, int divisor = 0, bool normalized = false) noexcept
			: index(index), type(type), num_components(num_components), offset(offset), divisor(divisor), normalized(normalized)
		{
		}

		uint32_t index;
		component_type type;
		int num_components;
		size_t offset;
		int divisor;
		bool normalized;
	};

	class mesh_core
	{
	public:
		virtual ~mesh_core() = default;

//		virtual void set_buffer_descriptions(const std::initializer_list<buffer_description> &descriptions) = 0;
		virtual void set_buffers(const std::initializer_list<buffer_index> &buffers) = 0;
		virtual void set_index_buffer(const buffer &buffer) = 0;
	};

	class mesh
	{
	public:
		mesh() noexcept = default;
		explicit mesh(std::unique_ptr<mesh_core> &&core) noexcept;

//		void set_buffer_descriptions(const std::initializer_list<buffer_description> &descriptions);
		void set_buffers(const std::initializer_list<buffer_index> &buffers);
		void set_index_buffer(const buffer &buffer);

		mesh_core &operator*() noexcept;
		const mesh_core &operator*() const noexcept;

	private:
		std::unique_ptr<mesh_core> core;
	};
}

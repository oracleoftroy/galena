#pragma once

#include <cstdint>
#include <vector>

#include <core/resource.hpp>
#include "buffer.hpp"

namespace gfx::gl
{
	class renderer;
	
	enum class component_type
	{
		int8,
		uint8,
		int16,
		uint16,
		int32,
		uint32,
		float32,
		float16,
		fixed,
		int32_2_10_10_10,
		uint32_2_10_10_10
	};

	struct vertex_attribute
	{
		vertex_attribute(component_type component_type, int num_components, uint32_t binding_index, size_t offset, int divisor = 0, bool normalized = false) noexcept;

		component_type type;
		int num_components;
		uint32_t  binding_index;
		size_t offset;
		int divisor;
		bool normalized;
	};

	class vertex_array_object final
	{
	public:
		vertex_array_object() = default;

		void use_vertex_buffer(uint32_t index, const buffer &buffer, size_t offset, size_t stride) noexcept;
		void use_index_buffer(const buffer &buffer) noexcept;

	private:
		friend class renderer;
		static uint32_t create_vao() noexcept;
		static void destroy_vao(uint32_t vao) noexcept;
		CORE_GENERATE_RESOURCE(vao_resource, uint32_t, create_vao, destroy_vao, core::resource::opts::implicit_conversion<true>);

		explicit vertex_array_object(vao_resource &&vao) noexcept;
		void bind_unsafe() noexcept;
		static void unbind_unsafe() noexcept;

	public:
		class builder final
		{
		public:
			builder() noexcept;
			~builder();

			void bind_index_buffer(const buffer &buffer) noexcept;
			void bind_vertex_buffer(uint32_t index, const buffer &buffer, size_t offset, size_t stride) noexcept;
			void bind_attribute(int index, const vertex_attribute &attribute) noexcept;
			vertex_array_object create() noexcept;

		private:
			vao_resource vao;
		};

	private:
		vao_resource vao;
	};
}

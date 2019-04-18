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
		vertex_attribute(component_type component_type, int num_components, int stride, size_t offset, int divisor = 0, bool normalized = false) noexcept;

		component_type type;
		int num_components;
		int stride;
		size_t offset;
		int divisor;
		bool normalized;
	};

	class renderer;

	class vertex_array_object final
	{
	public:
		vertex_array_object() = default;

	private:
		friend class renderer;
		static uint32_t create_vao(renderer &renderer) noexcept;
		static void destroy_vao(uint32_t vao) noexcept;
		CORE_GENERATE_RESOURCE(vao_resource, uint32_t, create_vao, destroy_vao, core::resource::opts::implicit_conversion<true>);

		explicit vertex_array_object(vao_resource &&vao) noexcept;
		void bind_unsafe() noexcept;
		static void unbind_unsafe() noexcept;

	public:
		class builder final
		{
		public:
			builder(renderer &renderer) noexcept;
			~builder();

			void bind_buffer(buffer_target target, buffer &buffer);
			void bind_attribute(int index, const vertex_attribute &attribute) noexcept;
			vertex_array_object create() noexcept;

		private:
			vao_resource vao;
			std::vector<buffer_target> bindings;
		};

	private:
		vao_resource vao;
	};
}

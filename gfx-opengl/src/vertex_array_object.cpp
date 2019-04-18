#include "vertex_array_object.hpp"

#include <utility>

#include <glad/glad.h>
//#include "renderer.hpp"
#include "log.hpp"

namespace gfx::gl
{
	namespace
	{
		static const GLenum component_types[] = {
			GL_BYTE,
			GL_UNSIGNED_BYTE,
			GL_SHORT,
			GL_UNSIGNED_SHORT,
			GL_INT,
			GL_UNSIGNED_INT,
			GL_FLOAT,

			GL_HALF_FLOAT,
			GL_FIXED,
			GL_INT_2_10_10_10_REV,
			GL_UNSIGNED_INT_2_10_10_10_REV
		};

		static constexpr GLenum to_gl(component_type type) noexcept
		{
			return component_types[static_cast<size_t>(type)];
		}
	}

	vertex_attribute::vertex_attribute(component_type type, int num_components, int stride, size_t offset, int divisor, bool normalized) noexcept
		: type(type), num_components(num_components), stride(stride), offset(offset), divisor(divisor), normalized(normalized)
	{
	}

	vertex_array_object::vertex_array_object(vao_resource &&vao) noexcept : vao(std::move(vao))
	{
	}

	void vertex_array_object::bind_unsafe() noexcept
	{
		glBindVertexArray(vao);
	}

	void vertex_array_object::unbind_unsafe() noexcept
	{
		glBindVertexArray(0);
	}

	uint32_t vertex_array_object::create_vao(renderer &) noexcept
	{
		uint32_t vao;
		glGenVertexArrays(1, &vao);
		return vao;
	}

	void vertex_array_object::destroy_vao(uint32_t vao) noexcept
	{
		glDeleteVertexArrays(1, &vao);
	}

	vertex_array_object::builder::builder(renderer &renderer) noexcept : vao(vao_resource::create(renderer))
	{
		glBindVertexArray(vao);
	}

	vertex_array_object::builder::~builder()
	{
		if ((GLuint)vao != 0)
		{
			LOG_WARN("create never called on vao builder!");
			glBindVertexArray(0);
		}
	}

	void vertex_array_object::builder::bind_buffer(buffer_target target, buffer &buffer)
	{
		buffer.bind_unsafe(target);
		bindings.emplace_back(target);
	}

	void vertex_array_object::builder::bind_attribute(int index, const vertex_attribute &attribute) noexcept
	{
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index,
			attribute.num_components,
			to_gl(attribute.type),
			attribute.normalized,
			attribute.stride,
			reinterpret_cast<void*>(attribute.offset));
		glVertexAttribDivisor(index, attribute.divisor);
	}

	vertex_array_object vertex_array_object::builder::create() noexcept
	{
		glBindVertexArray(0);

		for (auto &&target : bindings)
			buffer::unbind_unsafe(target);

		return vertex_array_object(std::move(vao));
	}
}

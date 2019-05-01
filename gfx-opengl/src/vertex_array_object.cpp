#include "vertex_array_object.hpp"

#include <utility>

#include <glad/glad.h>
#include "log.hpp"

namespace gfx::gl
{
	namespace
	{
		static constexpr GLenum component_types[] = {
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

	vertex_attribute::vertex_attribute(component_type type, int num_components, uint32_t binding_index, size_t offset, int divisor, bool normalized) noexcept
		: type(type), num_components(num_components), binding_index(binding_index), offset(offset), divisor(divisor), normalized(normalized)
	{
	}

	vertex_array_object::vertex_array_object(vao_resource &&vao) noexcept
		: vao(std::move(vao))
	{
	}

	void vertex_array_object::use_index_buffer(const buffer &buffer) noexcept
	{
		// "Bindless" version, should use glVertexArrayElementBuffer once available
		bind_unsafe();
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer.buf);
		unbind_unsafe();
	}

	void vertex_array_object::use_vertex_buffer(uint32_t index, const buffer &buffer, size_t offset, size_t stride) noexcept
	{
		// "Bindless" version, should use glVertexArrayVertexBuffer once available
		bind_unsafe();
		glBindVertexBuffer(index, buffer.buf, static_cast<GLintptr>(offset), static_cast<GLsizei>(stride));
		unbind_unsafe();
	}

	void vertex_array_object::bind_unsafe() const noexcept
	{
		glBindVertexArray(vao);
	}

	void vertex_array_object::unbind_unsafe() noexcept
	{
		glBindVertexArray(0);
	}

	uint32_t vertex_array_object::create_vao() noexcept
	{
		uint32_t vao;
		glGenVertexArrays(1, &vao);
		return vao;
	}

	void vertex_array_object::destroy_vao(uint32_t vao) noexcept
	{
		glDeleteVertexArrays(1, &vao);
	}

	vertex_array_object::builder::builder() noexcept : vao(vao_resource::create())
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

	void vertex_array_object::builder::bind_index_buffer(const buffer &buffer) noexcept
	{
		// glVertexArrayElementBuffer would probably be better once gles gets it
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer.buf);
	}

	void vertex_array_object::builder::bind_vertex_buffer(uint32_t index, const buffer &buffer, size_t offset, size_t stride) noexcept
	{
		// glVertexArrayVertexBuffer would probably be better once gles gets it
		glBindVertexBuffer(index, buffer.buf, static_cast<GLintptr>(offset), static_cast<GLsizei>(stride));
	}

	void vertex_array_object::builder::bind_attribute(uint32_t index, const vertex_attribute &attribute) noexcept
	{
		glEnableVertexAttribArray(index);
		glVertexAttribFormat(index, attribute.num_components, to_gl(attribute.type), attribute.normalized, static_cast<GLuint>(attribute.offset));
		glVertexAttribDivisor(index, static_cast<GLuint>(attribute.divisor));
		glVertexAttribBinding(index, attribute.binding_index);
	}

	vertex_array_object vertex_array_object::builder::create() noexcept
	{
		glBindVertexArray(0);
		return vertex_array_object(std::move(vao));
	}
}

#include "opengl_mesh_core.hpp"

#include <utility>
#include"opengl_buffer_core.hpp"
#include "../renderer.hpp"

namespace gfx::gl::detail
{
	std::unique_ptr<opengl_mesh_core> opengl_mesh_core::create(const std::initializer_list<buffer_description> &descriptions)
	{
		gl::vertex_array_object::builder builder;

		uint32_t index = 0;
		for (auto &desc : descriptions)
			builder.bind_attribute(index++, gl::vertex_attribute(static_cast<gl::component_type>(desc.type), desc.num_components, desc.index, desc.offset, desc.divisor, desc.normalized));

		return std::make_unique<opengl_mesh_core>(builder.create());
	}

	opengl_mesh_core::opengl_mesh_core(gl::vertex_array_object &&vao)
		: vao(std::move(vao))
	{
	}

	void opengl_mesh_core::set_buffers(const std::initializer_list<buffer_index> &buffers)
	{
		uint32_t index = 0;
		for (auto &buffer : buffers)
			vao.use_vertex_buffer(index++, static_cast<const opengl_buffer_core&>(*buffer.buffer.get()).get(), buffer.offset, buffer.stride);
	}

	void opengl_mesh_core::set_index_buffer(const gfx::buffer &buffer)
	{
		vao.use_index_buffer(static_cast<const opengl_buffer_core &>(*buffer).get());
	}

	void opengl_mesh_core::draw_indexed(gl::renderer &renderer, gfx::draw_mode mode, gfx::index_type type, int start, int count) const
	{
		renderer.use_vertex_array_object(vao);
		renderer.draw_indexed(static_cast<gl::draw_mode>(mode), static_cast<gl::index_type>(type), static_cast<size_t>(start), static_cast<size_t>(count));
	}
}

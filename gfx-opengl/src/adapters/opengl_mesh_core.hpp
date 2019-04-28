#pragma once

#include <gfx/mesh.hpp>
#include "../vertex_array_object.hpp"

namespace gfx::gl
{
	class renderer;
}

namespace gfx::gl::detail
{
	class opengl_mesh_core final : public mesh_core
	{
	public:
		static std::unique_ptr<opengl_mesh_core> create(const std::initializer_list<gfx::buffer_description> &descriptions);
		opengl_mesh_core(gl::vertex_array_object &&vao);

		void set_buffers(const std::initializer_list<gfx::buffer_index> &buffers) override;
		void set_index_buffer(const gfx::buffer &buffer) override;

		void draw_indexed(gl::renderer &renderer, gfx::draw_mode mode, gfx::index_type type, int start, int count) const;

	private:
		gl::vertex_array_object vao;
	};
}

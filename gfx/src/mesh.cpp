#include <gfx/mesh.hpp>

#include <utility>

namespace gfx
{
	mesh::mesh(std::unique_ptr<mesh_core> &&core) noexcept
		: core(std::move(core))
	{
	}

	void mesh::set_buffers(const std::initializer_list<buffer_index> &buffers)
	{
		core->set_buffers(buffers);
	}

	void mesh::set_index_buffer(const buffer &buffer)
	{
		core->set_index_buffer(buffer);
	}

	mesh_core &mesh::operator*() noexcept
	{
		return *core;
	}

	const mesh_core &mesh::operator*() const noexcept
	{
		return *core;

	}
}

#include <gfx/program.hpp>

#include <utility>

namespace gfx
{
	program::program(std::unique_ptr<program_core> &&core) noexcept
		: core(std::move(core))
	{
	}

	void program::set_uniform(int location, const glm::mat4 &matrix) noexcept
	{
		core->set_uniform(location, matrix);
	}

	const program_core &program::operator*() const
	{
		return *core;
	}
}

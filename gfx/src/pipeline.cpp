#include <gfx/pipeline.hpp>

#include <utility>
#include <gfx/program.hpp>

namespace gfx
{
	pipeline::pipeline(std::unique_ptr<pipeline_core> &&core) noexcept
		: core(std::move(core))
	{
	}

	void pipeline::use_program(const program &program)
	{
		core->use_program(program);
	}

	pipeline_core &pipeline::operator*()
	{
		return *core;
	}

	const pipeline_core &pipeline::operator*() const
	{
		return *core;
	}
}

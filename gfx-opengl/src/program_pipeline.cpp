#include "program_pipeline.hpp"

#include <utility>

#include <glad/glad.h>
#include "program.hpp"

namespace gfx::gl
{
	program_pipeline program_pipeline::create() noexcept
	{
		auto pipeline = program_pipeline_resource::create();
		return program_pipeline(std::move(pipeline));
	}

	program_pipeline::program_pipeline(program_pipeline_resource &&pipeline) noexcept
		: pipeline(std::move(pipeline))
	{
	}

	void program_pipeline::use_program(const program &program) noexcept
	{
		program.add_to_pipeline(pipeline);
	}

	void program_pipeline::unsafe_bind() noexcept
	{
		glBindProgramPipeline(pipeline);
	}
	
	void program_pipeline::unsafe_unbind() noexcept
	{
		glBindProgramPipeline(0);
	}

	uint32_t program_pipeline::create_program_pipeline() noexcept
	{
		GLuint pipeline;
		glGenProgramPipelines(1, &pipeline);
		return pipeline;
	}

	void program_pipeline::destroy_program_pipeline(uint32_t program_pipeline) noexcept
	{
		glDeleteProgramPipelines(1, &program_pipeline);
	}
}

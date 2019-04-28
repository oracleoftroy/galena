#include <gfx/gl/opengl_renderer_core.hpp>

#include "opengl_pipeline_core.hpp"
#include "opengl_program_core.hpp"
#include "../program_pipeline.hpp"

namespace gfx::gl::detail
{
	std::unique_ptr<opengl_pipeline_core> opengl_pipeline_core::create()
	{
		return std::make_unique<opengl_pipeline_core>(gl::program_pipeline::create());
	}

	opengl_pipeline_core::opengl_pipeline_core(gl::program_pipeline &&pipeline) noexcept
		: pipeline(std::move(pipeline))
	{
	}

	gl::program_pipeline &opengl_pipeline_core::get() noexcept
	{
		return pipeline;
	}

	void opengl_pipeline_core::use_program(const gfx::program &p)
	{
		auto &program = static_cast<const opengl_program_core &>(*p);
		pipeline.use_program(program.get());
	}
}

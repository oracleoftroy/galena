#pragma once

#include <gfx/pipeline.hpp>
#include "../program_pipeline.hpp"

namespace gfx::gl::detail
{
	class opengl_pipeline_core : public gfx::pipeline_core
	{
	public:
		static std::unique_ptr<opengl_pipeline_core> create();
		explicit opengl_pipeline_core(gl::program_pipeline &&pipeline) noexcept;

		gl::program_pipeline &get() noexcept;
		void use_program(const gfx::program &program) override;

	private:
		gl::program_pipeline pipeline;
	};
}

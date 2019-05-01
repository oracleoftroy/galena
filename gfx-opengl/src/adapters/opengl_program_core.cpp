#include "opengl_program_core.hpp"
#include <gfx/gl/opengl_renderer_core.hpp>

#include <gfx/program.hpp>
#include "../program.hpp"

namespace gfx::gl::detail
{
	std::unique_ptr<opengl_program_core> opengl_program_core::create(gfx::program_type type, const fs::path &file_path)
	{
		// TODO: figure out a way to generate a compiler error if types mismatch
		// TODO: support more shader types
		gl::program_type shader_type = type == gfx::program_type::vertex ? gl::program_type::vertex : gl::program_type::fragment;

		return std::make_unique<opengl_program_core>(gl::program::create(shader_type, file_path));
	}

	opengl_program_core::opengl_program_core(gl::program &&program) noexcept
		: program(std::move(program))
	{
	}

	void opengl_program_core::set_uniform(int location, const glm::mat4 &matrix) noexcept
	{
		program.set_uniform(location, matrix);
	}

	gl::program &opengl_program_core::get() noexcept
	{
		return program;
	}

	const gl::program &opengl_program_core::get() const noexcept
	{
		return program;
	}
}

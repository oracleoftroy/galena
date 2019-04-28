#pragma once

#include <gfx/program.hpp>
#include "../program.hpp"

namespace gfx::gl::detail
{
	class opengl_program_core : public gfx::program_core
	{
	public:
		static std::unique_ptr<opengl_program_core> create(gfx::program_type type, const std::filesystem::path &file_path);
		explicit opengl_program_core(gl::program &&program) noexcept;

		void set_uniform(int location, const glm::mat4 &matrix) noexcept override;

		gl::program &get() noexcept;
		const gl::program &get() const noexcept;

	private:
		gl::program program;
	};
}

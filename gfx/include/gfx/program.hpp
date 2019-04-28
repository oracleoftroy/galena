#pragma once

#include <memory>
#include <glm/glm.hpp>

namespace gfx
{
	enum class program_type
	{
		vertex,
		fragment
	};

	class program_core
	{
	public:
		virtual ~program_core() = default;

		virtual void set_uniform(int location, const glm::mat4 &matrix) noexcept = 0;
	};

	class program
	{
	public:
		program() noexcept = default;
		explicit program(std::unique_ptr<program_core> &&core) noexcept;

		void set_uniform(int location, const glm::mat4 &matrix) noexcept;

		const program_core &operator*() const;

	private:
		std::unique_ptr<program_core> core;
	};
}

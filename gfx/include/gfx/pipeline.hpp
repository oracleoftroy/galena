#pragma once

#include <memory>

namespace gfx
{
	class program;

	class pipeline_core
	{
	public:
		virtual ~pipeline_core() = default;

		virtual void use_program(const program &program) = 0;
	};

	class pipeline
	{
	public:
		pipeline() noexcept = default;
		explicit pipeline(std::unique_ptr<pipeline_core> &&core) noexcept;

		void use_program(const program &program);

		template <typename ...Programs>
		void use_programs(Programs&&... programs);

		pipeline_core &operator*();
		const pipeline_core &operator*() const;

	private:
		std::unique_ptr<pipeline_core> core;
	};

	template <typename ...Programs>
	void pipeline::use_programs(Programs &&... programs)
	{
		//static_assert((... && std::is_same_v<gfx::program, Programs>));
		(use_program(programs),...);
	}
}

#pragma once

#include <array>
#include <cstdint>

#include <core/resource.hpp>

namespace gfx::gl
{
	class program;
	class renderer;

	class program_pipeline final
	{
	public:
		static program_pipeline create() noexcept;
		program_pipeline() = default;

		void use_program(const program &program) noexcept;

		template <typename ...Programs>
		void use_programs(const Programs &...program) noexcept;

	private:
		static uint32_t create_program_pipeline() noexcept;
		static void destroy_program_pipeline(uint32_t program_pipeline) noexcept;
		CORE_GENERATE_RESOURCE(program_pipeline_resource, uint32_t, create_program_pipeline, destroy_program_pipeline, core::resource::opts::implicit_conversion<true>);

		explicit program_pipeline(program_pipeline_resource &&pipeline) noexcept;
		void unsafe_bind() noexcept;
		static void unsafe_unbind() noexcept;

	private:
		friend class renderer;
		program_pipeline_resource pipeline;
	};

	template <typename ...Programs>
	void program_pipeline::use_programs(const Programs &...ps) noexcept
	{
		auto programs = std::array<const program *, sizeof...(ps)> { &ps... };
		for (auto &&program : programs)
			use_program(*program);
	}
}

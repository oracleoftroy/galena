#pragma once

#include <glm/glm.hpp>

#include <cstdint>
#include <string>
#include <core/resource.hpp>

namespace gfx::gl
{
	enum class program_type
	{
		compute,
		vertex,
		tess_control,
		tess_evaluation,
		geometry,
		fragment
	};

	class renderer;

	class program
	{
	public:
		static program create(renderer &renderer, program_type type, const std::string &source);
		program() = default;

		program_type get_type() noexcept { return type; }

		void set_uniform(int32_t uniform, int value) noexcept;
		void set_uniform(int32_t uniform, const glm::mat4 &value) noexcept;
		void set_uniform(int32_t uniform, float v1, float v2, float v3, float v4) noexcept;
		void set_uniform(int32_t uniform, const glm::vec3 &value) noexcept;
		void set_uniform(int32_t uniform, const glm::vec4 &value) noexcept;
		
		int32_t uniform_location(const char *name) noexcept;

	private:
		static uint32_t create_program(renderer &renderer, program_type type, const std::string &source) noexcept;
		static void destroy_program(uint32_t program) noexcept;
		CORE_GENERATE_RESOURCE(program_resource, uint32_t, create_program, destroy_program, core::resource::opts::implicit_conversion<true>);

		explicit program(program_type type, program_resource &&resource) noexcept;
		
		friend class program_pipeline;
		void add_to_pipeline(uint32_t pipeline) const;

	private:
		program_type type;
		program_resource resource;
	};
}

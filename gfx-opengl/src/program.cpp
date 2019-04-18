#include "program.hpp"

#include <stdexcept>
#include <utility>
#include <vector>

#include <glm/gtc/type_ptr.hpp>

#include <glad/glad.h>
#include "log.hpp"

namespace gfx::gl
{
	namespace
	{
		static const GLenum shader_types[] =
		{
			GL_COMPUTE_SHADER,
			GL_VERTEX_SHADER,
			GL_TESS_CONTROL_SHADER,
			GL_TESS_EVALUATION_SHADER,
			GL_GEOMETRY_SHADER,
			GL_FRAGMENT_SHADER
		};

		static const GLenum shader_flags[] =
		{
			GL_COMPUTE_SHADER_BIT,
			GL_VERTEX_SHADER_BIT,
			GL_TESS_CONTROL_SHADER_BIT,
			GL_TESS_EVALUATION_SHADER_BIT,
			GL_GEOMETRY_SHADER_BIT,
			GL_FRAGMENT_SHADER_BIT,
		};

		static const char *type_strings[]
		{
			"compute",
			"vertex",
			"tess_control",
			"tess_evaluation",
			"geometry",
			"fragment"
		};

		constexpr GLenum to_gl(program_type type) noexcept
		{
			return shader_types[static_cast<size_t>(type)];
		}

		constexpr GLenum to_gl_bits(program_type type) noexcept
		{
			return shader_flags[static_cast<size_t>(type)];
		}

		constexpr const char *c_str(program_type type) noexcept
		{
			return type_strings[static_cast<size_t>(type)];
		}
	}

	struct program_error : public std::runtime_error
	{
		program_error(const std::string &what) : std::runtime_error(what)
		{
		}
	};

	program program::create(renderer &renderer, program_type type, const std::string &source)
	{
		LOG_INFO("Creating %s program", c_str(type));

		auto resource = program_resource::create(renderer, type, source);

		GLint success = 0;
		glGetProgramiv(resource, GL_LINK_STATUS, &success);

		if (!success)
		{
			GLint log_length = 0;
			glGetProgramiv(resource, GL_INFO_LOG_LENGTH, &log_length);

			std::vector<GLchar> log(log_length);
			glGetProgramInfoLog(resource, log_length, &log_length, log.data());

			LOG_ERROR("Error creating program: %s", log.data());
			LOG_TRACE("Program source:\n---\n%s\n---", source.c_str());

			throw program_error(std::string(begin(log), end(log)));
		}

		return program(type, std::move(resource));
	}

	program::program(program_type type, program_resource &&resource) noexcept
		: type(type), resource(std::move(resource))
	{
	}

	void program::set_uniform(int32_t uniform, int value) noexcept
	{
		glProgramUniform1i(resource, uniform, value);
	}

	void program::set_uniform(int32_t uniform, const glm::mat4 &value) noexcept
	{
		glProgramUniformMatrix4fv(resource, uniform, 1, GL_FALSE, glm::value_ptr(value));
	}

	void program::set_uniform(int32_t uniform, float v1, float v2, float v3, float v4) noexcept
	{
		glProgramUniform4f(resource, uniform, v1, v2, v3, v4);
	}

	void program::set_uniform(int32_t uniform, const glm::vec3 &value) noexcept
	{
		glProgramUniform3fv(resource, uniform, 1, glm::value_ptr(value));
	}

	void program::set_uniform(int32_t uniform, const glm::vec4 &value) noexcept
	{
		glProgramUniform4fv(resource, uniform, 1, glm::value_ptr(value));
	}

	int32_t program::uniform_location(const char *name) noexcept
	{
		return glGetProgramResourceLocation(resource, GL_UNIFORM, name);
	}

	void program::add_to_pipeline(uint32_t pipeline) const
	{
		glUseProgramStages(pipeline, to_gl_bits(type), resource);
	}

	uint32_t program::create_program(renderer &, program_type type, const std::string &source) noexcept
	{
		const char *s = source.c_str();
		return glCreateShaderProgramv(to_gl(type), 1, &s);
	}

	void program::destroy_program(uint32_t program) noexcept
	{
		glDeleteProgram(program);
	}
}

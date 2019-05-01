#include "program.hpp"

#include <fstream>
#include <optional>
#include <stdexcept>
#include <string_view>
#include <utility>
#include <vector>

#include <glm/gtc/type_ptr.hpp>

#include <glad/glad.h>
#include "log.hpp"

using namespace std::string_view_literals;

namespace gfx::gl
{
	namespace
	{
		static constexpr GLenum shader_types[] =
		{
			GL_COMPUTE_SHADER,
			GL_VERTEX_SHADER,
			GL_TESS_CONTROL_SHADER,
			GL_TESS_EVALUATION_SHADER,
			GL_GEOMETRY_SHADER,
			GL_FRAGMENT_SHADER
		};

		static constexpr GLenum shader_flags[] =
		{
			GL_COMPUTE_SHADER_BIT,
			GL_VERTEX_SHADER_BIT,
			GL_TESS_CONTROL_SHADER_BIT,
			GL_TESS_EVALUATION_SHADER_BIT,
			GL_GEOMETRY_SHADER_BIT,
			GL_FRAGMENT_SHADER_BIT,
		};

		static constexpr std::string_view type_strings[]
		{
			"compute"sv,
			"vertex"sv,
			"tess_control"sv,
			"tess_evaluation"sv,
			"geometry"sv,
			"fragment"sv
		};

		constexpr GLenum to_gl(program_type type) noexcept
		{
			return shader_types[static_cast<size_t>(type)];
		}

		constexpr GLenum to_gl_bits(program_type type) noexcept
		{
			return shader_flags[static_cast<size_t>(type)];
		}

		constexpr const std::string_view str(program_type type) noexcept
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

	static std::optional<std::string> read_file(const fs::path &file_path)
	{
		std::ifstream file(file_path, std::ios::binary);

		if (!file)
			return {};

		std::string source;

		file.seekg(0, std::ios::end);
		source.resize(static_cast<size_t>(file.tellg()));
		file.seekg(0, std::ios::beg);

		file.read(source.data(), static_cast<std::streamsize>(source.size()));

		return source;
	}

	program program::create(program_type type, const fs::path &file_path)
	{
		LOG_INFO("loading {0} program from {1}", str(type), file_path.u8string());

		auto source = read_file(file_path);

		if (!source)
		{
			if (!fs::exists(file_path))
			{
				LOG_ERROR("Error opening file {0} - File does not exist", file_path.u8string());
				throw program_error(fmt::format("Error opening file {0} - File does not exist", file_path.u8string()));
			}
			else
			{
				// see if there are other reasons we can report
				LOG_ERROR("Error opening file {0}", file_path.u8string());
				throw program_error(fmt::format("Error opening file {0}", file_path.u8string()));
			}
		}

		return create(type, *source);
	}

	program program::create(program_type type, const std::string &source)
	{
		LOG_INFO("Creating {0} program", str(type));

		auto resource = program_resource::create(type, source);

		GLint success = 0;
		glGetProgramiv(resource, GL_LINK_STATUS, &success);

		if (!success)
		{
			GLint log_length = 0;
			glGetProgramiv(resource, GL_INFO_LOG_LENGTH, &log_length);

			std::vector<GLchar> log(static_cast<size_t>(log_length));
			glGetProgramInfoLog(resource, log_length, &log_length, log.data());

			LOG_ERROR("Error creating program: {0}", log.data());
			LOG_TRACE("Program source:\n---\n{0}\n---", source.c_str());

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

	uint32_t program::create_program(program_type type, const std::string &source) noexcept
	{
		const char *s = source.c_str();
		return glCreateShaderProgramv(to_gl(type), 1, &s);
	}

	void program::destroy_program(uint32_t program) noexcept
	{
		glDeleteProgram(program);
	}
}

#pragma once

#if __has_include(<filesystem>)
#include <filesystem>
namespace fs = std::filesystem;
#elif __has_include(<experimental/filesystem>)
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#else
#error "Cannot find <filesystem>"
#endif

#include <memory>
#include <glm/glm.hpp>

#include <gfx/buffer.hpp>
#include <gfx/mesh.hpp>
#include <gfx/program.hpp>
#include <gfx/pipeline.hpp>

namespace gfx
{
	namespace imgui
	{
		class imgui_graphics_core;
	}

	class renderer_core
	{
	public:
		virtual ~renderer_core() = default;

		virtual buffer create_buffer(buffer_type type, usage_hint hint, const void *data, size_t size) = 0;
		virtual program create_program(program_type type, const fs::path &file_path) = 0;
		virtual pipeline create_pipeline() = 0;
		virtual mesh create_mesh(const std::initializer_list<buffer_description> &descriptions) = 0;
		virtual std::unique_ptr<imgui::imgui_graphics_core> create_imgui_graphics_core() = 0;

		virtual void set_viewport(const glm::ivec2 &p, const glm::ivec2 &size) noexcept = 0;
		virtual void set_clear_color(float r, float g, float b, float a) noexcept = 0;

		virtual void clear_depth() noexcept = 0;
		virtual void clear_color() noexcept = 0;
		virtual void use_pipeline(pipeline &pipeline) = 0;
		virtual void draw_indexed_mesh(const mesh &m, draw_mode mode, index_type type, size_t start, size_t count) = 0;
	};

	class renderer
	{
	public:
		renderer() noexcept = default;
		explicit renderer(std::unique_ptr<renderer_core> &&core) noexcept;

		// creation functions
		buffer create_buffer(buffer_type type, usage_hint hint, const void *data, size_t size);
		program create_program(program_type type, const fs::path &file_path);
		pipeline create_pipeline();
		mesh create_mesh(const std::initializer_list<buffer_description> &descriptions);

		std::unique_ptr<imgui::imgui_graphics_core> create_imgui_graphics_core();

		// state functions
		void set_viewport(const glm::ivec2 &p, const glm::ivec2 &size) noexcept;
		void set_clear_color(float r, float g, float b, float a) noexcept;

		// rendering functions
		void clear_color() noexcept;
		void clear_depth() noexcept;
		void use_pipeline(pipeline &pipeline);
		void draw_indexed_mesh(const mesh &m, draw_mode mode, index_type type, size_t start, size_t count);

	private:
		std::unique_ptr<renderer_core> core;
	};
}


#include <gfx/renderer.hpp>

#include <gfx/buffer.hpp>
//#include <gfx/pipeline.hpp>
//#include <gfx/program.hpp>
#include <gfx/imgui_graphics.hpp>
#include <utility>

namespace gfx
{
	renderer::renderer(std::unique_ptr<renderer_core> &&core) noexcept
		: core(std::move(core))
	{
	}

	void renderer::set_viewport(const glm::ivec2 &p, const glm::ivec2 &size) noexcept
	{
		core->set_viewport(p, size);
	}

	void renderer::set_clear_color(float r, float g, float b, float a) noexcept
	{
		core->set_clear_color(r, g, b, a);
	}

	void renderer::clear_color() noexcept
	{
		core->clear_color();
	}

	void renderer::clear_depth() noexcept
	{
		core->clear_depth();
	}

	buffer renderer::create_buffer(buffer_type type, usage_hint hint, const void *data, size_t size)
	{
		return core->create_buffer(type, hint, data, size);
	}

	program renderer::create_program(program_type type, const fs::path &file_path)
	{
		return core->create_program(type, file_path);
	}

	pipeline renderer::create_pipeline()
	{
		return core->create_pipeline();
	}

	mesh renderer::create_mesh(const std::initializer_list<buffer_description> &descriptions)
	{
		return core->create_mesh(descriptions);
	}

	std::unique_ptr<imgui::imgui_graphics_core> renderer::create_imgui_graphics_core()
	{
		return core->create_imgui_graphics_core();
	}

	void renderer::use_pipeline(pipeline &pipeline)
	{
		core->use_pipeline(pipeline);
	}

	void renderer::draw_indexed_mesh(const mesh &m, draw_mode mode, index_type type, int start, int count)
	{
		core->draw_indexed_mesh(m, mode, type, start, count);
	}
}

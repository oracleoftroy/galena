#pragma once

#include <gfx/renderer.hpp>
#include <glm/glm.hpp>

namespace app
{
	class test_app
	{
	public:
		static test_app create(gfx::renderer &renderer, const glm::vec2 &view_size);
		test_app();

		void tick(double delta);

		void render(gfx::renderer &renderer);

	private:
		test_app(const glm::vec2 &view_size, gfx::buffer &&positions_buffer, gfx::buffer &&colors_buffer, gfx::buffer &&indices_buffer, gfx::program &&vertex_program, gfx::program &&fragment_program, gfx::pipeline &&pipeline, gfx::mesh &&mesh);

		gfx::buffer positions_buffer;
		gfx::buffer colors_buffer;
		gfx::buffer indices_buffer;
		gfx::program vertex_program;
		gfx::program fragment_program;
		gfx::pipeline pipeline;
		gfx::mesh mesh;
		glm::mat4 proj_view;
		glm::mat4 model;
		double accum = 0;
	};
}

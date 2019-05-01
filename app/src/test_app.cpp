#include "test_app.hpp"

#include <array>
#include <gfx/buffer.hpp>
#include <gfx/mesh.hpp>
#include <gfx/renderer.hpp>
#if defined(_WIN32)
#pragma warning (push)
#pragma warning (disable: 4127) // conditional expression is constant
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#if defined(_WIN32)
#pragma warning (pop)
#endif

namespace app
{
	constexpr uint16_t operator "" _u16(unsigned long long v) noexcept
	{
		return uint16_t(v);
	}

	test_app test_app::create(gfx::renderer &renderer, const glm::vec2 &view_size)
	{
		std::array positions =
		{
			glm::vec3{-0.5f, -0.5f, -0.5f},
			glm::vec3{0.5f, -0.5f, -0.5f},
			glm::vec3{-0.5f, 0.5f, -0.5f},
			glm::vec3{-0.5f, -0.5f, 0.5f},
			glm::vec3{0.5f, 0.5f, -0.5f},
			glm::vec3{0.5f, -0.5f, 0.5f},
			glm::vec3{-0.5f, 0.5f, 0.5f},
			glm::vec3{0.5f, 0.5f, 0.5f},
		};
		static_assert(sizeof(positions) == positions.size() * sizeof(positions[0]));

		std::array colors =
		{
			glm::vec3{0.0f, 0.0f, 0.0f},
			glm::vec3{1.0f, 0.0f, 0.0f},
			glm::vec3{0.0f, 1.0f, 0.0f},
			glm::vec3{0.0f, 0.0f, 1.0f},
			glm::vec3{1.0f, 1.0f, 0.0f},
			glm::vec3{1.0f, 0.0f, 1.0f},
			glm::vec3{0.0f, 1.0f, 1.0f},
			glm::vec3{1.0f, 1.0f, 1.0f},
		};
		static_assert(sizeof(colors) == colors.size() * sizeof(colors[0]));

		std::array indices =
		{
			0_u16, 2_u16, 4_u16,
			0_u16, 4_u16, 1_u16,
			1_u16, 4_u16, 7_u16,
			1_u16, 7_u16, 5_u16,
			5_u16, 7_u16, 6_u16,
			5_u16, 6_u16, 3_u16,
			3_u16, 6_u16, 2_u16,
			3_u16, 2_u16, 0_u16,
			6_u16, 4_u16, 2_u16,
			6_u16, 7_u16, 4_u16,
			1_u16, 3_u16, 0_u16,
			1_u16, 5_u16, 3_u16,
		};
		static_assert(sizeof(indices) == indices.size() * sizeof(indices[0]));

		gfx::buffer positions_buffer = renderer.create_buffer(gfx::buffer_type::vertex, gfx::usage_hint::read_only, positions.data(), sizeof(positions));
		gfx::buffer colors_buffer = renderer.create_buffer(gfx::buffer_type::vertex, gfx::usage_hint::read_only, colors.data(), sizeof(colors));
		gfx::buffer indices_buffer = renderer.create_buffer(gfx::buffer_type::index, gfx::usage_hint::read_only, indices.data(), sizeof(indices));

		gfx::mesh mesh = renderer.create_mesh(
		{
			gfx::buffer_description(0, gfx::component_type::float32, 3, 0),
			gfx::buffer_description(1, gfx::component_type::float32, 3, 0),
		});

		mesh.set_buffers({
			gfx::buffer_index(0, positions_buffer, sizeof(positions[0]), 0),
			gfx::buffer_index(1, colors_buffer, sizeof(colors[0]), 0),
		});

		mesh.set_index_buffer(indices_buffer);

		gfx::program vertex_program = renderer.create_program(gfx::program_type::vertex, "shaders/vertex.vert");
		gfx::program fragment_program = renderer.create_program(gfx::program_type::fragment, "shaders/fragment.frag");

		gfx::pipeline pipeline = renderer.create_pipeline();
		pipeline.use_programs(vertex_program, fragment_program);

		return test_app(view_size, std::move(positions_buffer), std::move(colors_buffer), std::move(indices_buffer), std::move(vertex_program), std::move(fragment_program), std::move(pipeline), std::move(mesh));
	}

	test_app::test_app()
	{
	}

	test_app::test_app(const glm::vec2 &view_size, gfx::buffer &&positions_buffer, gfx::buffer &&colors_buffer, gfx::buffer &&indices_buffer, gfx::program &&vertex_program, gfx::program &&fragment_program, gfx::pipeline &&pipeline, gfx::mesh &&mesh)
		: positions_buffer(std::move(positions_buffer)), colors_buffer(std::move(colors_buffer)), indices_buffer(std::move(indices_buffer)), vertex_program(std::move(vertex_program)), fragment_program(std::move(fragment_program)), pipeline(std::move(pipeline)), mesh(std::move(mesh))
	{
		auto projection = glm::perspectiveFov(45.0f, view_size.x, view_size.y, 1.0f, 100.0f);
		auto camera = glm::translate(glm::identity<glm::mat4>(), glm::vec3(0.0f, 0.0f, -70.0f));
		proj_view = projection * glm::scale(camera, glm::vec3(10.0f, 10.0f, 10.0f));
	}

	void test_app::tick([[maybe_unused]]double delta)
	{
		const glm::vec3 axis(2.0f, 3.0f, 5.0f);
		const float angle = 3.0f;

		accum += delta;

		model = glm::identity<glm::mat4>();
		model = glm::translate(model, glm::vec3(4.0f * sin(accum * 0.9f), 3.0f * cos(accum * 1.0f), 2.5f * cos(accum * 0.5f)));
		model = glm::rotate(model, static_cast<float>(angle * accum), axis);
	}

	void test_app::render(gfx::renderer &renderer)
	{
		renderer.clear_depth();
		renderer.use_pipeline(pipeline);
		vertex_program.set_uniform(0, proj_view * model);
		renderer.draw_indexed_mesh(mesh, gfx::draw_mode::triangles, gfx::index_type::uint16, 0, 36);
	}
}

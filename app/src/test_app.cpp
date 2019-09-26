#include "test_app.hpp"

#include <algorithm>
#include <array>
#include <cmath>
#include <gfx/buffer.hpp>
#include <gfx/mesh.hpp>
#include <gfx/renderer.hpp>
#if defined(_WIN32)
#pragma warning (push)
#pragma warning (disable: 4127) // conditional expression is constant
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/noise.hpp>
#if defined(_WIN32)
#pragma warning (pop)
#endif

template <typename Real>
constexpr Real pi = glm::pi<Real>();

namespace app
{
	// generates a grid with <count> points and <spacing> space between points. the z value will be assigned to noise. Origin will be the center of the grid
	// returns the positions and an index vector representing how to draw triangle_strips
	std::pair<std::vector<glm::vec3>, std::vector<uint16_t>> generate_terrain(const glm::ivec2 &count, const glm::vec2 &spacing)
	{
		glm::vec2 size = spacing * static_cast<glm::vec2>(count);
		glm::vec2 center = size / 2.0f;
		glm::vec2 start = center - size;

		std::vector<glm::vec3> points;
		std::vector<uint16_t> indices;
		points.reserve(static_cast<size_t>(count.x * count.y));

		// overestimate: each point is drawn twice, except for the top and bottom row, plus we will draw one degenerate triangle per row
		indices.reserve(static_cast<size_t>(count.x * count.y * 2 + count.y * 2));

		auto index = [&count](int x, int y) { return static_cast<uint16_t>(y * count.x + x); };

		for (int y = 0; y < count.y; ++y)
		{
			// degenerate triangle, re-add our last vertex and add our first one
			if (y > 0)
			{
				indices.emplace_back(index(count.x - 1, y - 1));
				indices.emplace_back(index(0, y + 1));
			}

			for (int x = 0; x < count.x; ++x)
			{
				auto sample = glm::vec2(x, y) * 0.05f;
				auto noise = 0.0f;

				for (int octave = 0; octave < 16; ++octave)
				{
					float scale = powf(2.0f, static_cast<float>(octave));
					noise += 1.0f / scale * glm::simplex(sample * scale);
				}

				points.emplace_back(start.x + static_cast<float>(x) * spacing.x, start.y + static_cast<float>(y) * spacing.y, noise * 3.0f);

				// skip the last row of indexes
				if (y < (count.y - 1))
				{
					indices.emplace_back(index(x, y + 1));
					indices.emplace_back(index(x, y));
				}
			}
		}

		return {std::move(points), std::move(indices)};
	}

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

		auto [terrain_pos, terrain_idx] = generate_terrain({200, 100}, {1, 1});
		std::vector<glm::vec3> terrain_colors(terrain_pos.size());

		auto [min, max] = std::minmax_element(begin(terrain_pos), end(terrain_pos), [](const auto & v1, const auto & v2) { return v1.z < v2.z; });

		std::transform(begin(terrain_pos), end(terrain_pos), begin(terrain_colors), [min = min, max = max]([[maybe_unused]]const glm::vec3 & pos)
			{
				auto brownish = glm::vec3{0.353f, 0.174f, 0.088f};
				auto snow = glm::vec3{1.0f, 1.0f, 1.0f};
				//return glm::clamp(
				return glm::mix(brownish, snow, (pos.z - min->z) / (max->z - min->z));// ,
				//	brownish, snow);

//				return glm::vec3{0.5f, 0.5f, 0.5f};
			});

		auto terrain_buf = renderer.create_buffer(gfx::buffer_type::vertex, gfx::usage_hint::read_only, terrain_pos.data(), terrain_pos.size() * sizeof(terrain_pos[0]));
		auto terrain_colorsbuf = renderer.create_buffer(gfx::buffer_type::vertex, gfx::usage_hint::read_only, terrain_colors.data(), terrain_colors.size() * sizeof(terrain_colors[0]));
		auto terrain_idxbuf = renderer.create_buffer(gfx::buffer_type::index, gfx::usage_hint::read_only, terrain_idx.data(), terrain_idx.size() * sizeof(terrain_idx[0]));

		auto terrain_mesh = renderer.create_mesh({
			gfx::buffer_description(0, gfx::component_type::float32, 3, 0),
			gfx::buffer_description(1, gfx::component_type::float32, 3, 0),
		});

		terrain_mesh.set_buffers({
			gfx::buffer_index(0, terrain_buf, sizeof(terrain_pos[0]), 0),
			gfx::buffer_index(1, terrain_colorsbuf, sizeof(terrain_colors[0]), 0),
		});

		terrain_mesh.set_index_buffer(terrain_idxbuf);

		return test_app(view_size, std::move(positions_buffer), std::move(colors_buffer), std::move(indices_buffer), std::move(vertex_program), std::move(fragment_program), std::move(pipeline), std::move(mesh), std::move(terrain_buf), std::move(terrain_colorsbuf), std::move(terrain_idxbuf), std::move(terrain_mesh), terrain_idx.size());
	}

	test_app::test_app()
	{
	}

	test_app::test_app(const glm::vec2 &view_size, gfx::buffer &&positions_buffer, gfx::buffer &&colors_buffer, gfx::buffer &&indices_buffer, gfx::program &&vertex_program, gfx::program &&fragment_program, gfx::pipeline &&pipeline, gfx::mesh &&mesh, gfx::buffer &&terrain_buf, gfx::buffer &&terrain_colorsbuf, gfx::buffer &&terrain_idxbuf, gfx::mesh &&terrain_mesh, size_t terrain_idx_count)
		: positions_buffer(std::move(positions_buffer)), colors_buffer(std::move(colors_buffer)), indices_buffer(std::move(indices_buffer)), vertex_program(std::move(vertex_program)), fragment_program(std::move(fragment_program)), pipeline(std::move(pipeline)), mesh(std::move(mesh)),
		terrain_buf(std::move(terrain_buf)), terrain_colorsbuf(std::move(terrain_colorsbuf)), terrain_idxbuf(std::move(terrain_idxbuf)), terrain_mesh(std::move(terrain_mesh)), terrain_idx_count(terrain_idx_count)
	{
		auto projection = glm::perspectiveFov(45.0f, view_size.x, view_size.y, 1.0f, 10000.0f);
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

		auto m = glm::identity<glm::mat4>();
		m = glm::translate(m, {0.0f, -25.0f, -50.0f});
		m = glm::rotate(m, pi<float> * -0.3f, {1.0f, 0.0f, 0.0f});
		vertex_program.set_uniform(0, proj_view * m);
		renderer.draw_indexed_mesh(terrain_mesh, gfx::draw_mode::triangle_strip, gfx::index_type::uint16, 0, terrain_idx_count);

		vertex_program.set_uniform(0, proj_view * model);
		renderer.draw_indexed_mesh(mesh, gfx::draw_mode::triangles, gfx::index_type::uint16, 0, 36);
	}
}

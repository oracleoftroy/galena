#pragma once

#include <glm/glm.hpp>

#include <cstdint>
#include <vector>
#include <core/log_subsystem.hpp>

namespace ui
{
	class opengl_context;
}

namespace gfx::gl
{
	enum class framebuffer_target;

	enum class feature
	{
		blending,
		face_culling,
		debug_output,
		depth_test,
		dithering,
		polygon_offset_fill,
		primitive_restart_fixed_index,
		rasterizer_discard,
		sample_alpha_to_coverage,
		sample_coverage,
		sample_mask,
		scissor_test,
		stencil_test
	};

	enum class blend_function
	{
		zero,
		one,
		source_color,
		one_minus_source_color,
		dest_color,
		one_minus_dest_color,
		source_alpha,
		one_minus_source_alpha,
		dest_alpha,
		one_minus_dest_alpha,
		constant_color,
		one_minus_constant_color,
		constant_alpha,
		one_minus_constant_alpha,
		alpha_saturate
	};

	enum class blend_equation
	{
		add,
		source_minus_dest,
		dest_minus_source,
		min,
		max
	};

	enum class draw_mode
	{
		points,
		lines,
		line_loop,
		line_strip,
		triangles,
		triangle_strip,
		triangle_fan,
	};

	enum class index_type
	{
		uint8,
		uint16,
		uint32,
	};

	class framebuffer;
	class program_pipeline;
	class sampler;
	class texture;
	class vertex_array_object;

	class renderer final
	{
	public:
		explicit renderer(const ui::opengl_context &context) noexcept;

		void enable(feature feature) noexcept;
		void disable(feature feature) noexcept;

		void set_viewport(const glm::ivec2 &p, const glm::ivec2 &size)  noexcept;

		void set_blend_color(float r, float g, float b, float a) noexcept;
		void set_blend_function(blend_function source, blend_function dest) noexcept;
		void set_blend_function(blend_function rgbSource, blend_function rgbDest, blend_function alphaSource, blend_function alphaDest) noexcept;
		void set_blend_equation(blend_equation equation) noexcept;
		void set_blend_equation(blend_equation rgb, blend_equation alpha) noexcept;

		void set_clear_color(float r, float g, float b, float a) noexcept;
		void set_clear_depth(float depth) noexcept;
		void set_clear_stencil(int stencil) noexcept;

		void clear_color() noexcept;
		void clear_depth() noexcept;
		void clear_stencil() noexcept;

		void use_vertex_array_object(const vertex_array_object &vao) noexcept;
		void clear_vertex_array_object() noexcept;

		void use_program_pipeline(program_pipeline &pipeline) noexcept;
		void clear_program_pipeline() noexcept;

		void use_texture(int texture_unit, texture &texture, sampler &sampler) noexcept;
		void clear_texture(int texture_unit) noexcept;

		void use_framebuffer(framebuffer_target target, framebuffer &buffer) noexcept;
		void clear_framebuffer(framebuffer_target target) noexcept;

		void draw(draw_mode mode, size_t start, size_t count) noexcept;
		void draw_indexed(draw_mode mode, index_type type, size_t start, size_t count) noexcept;
		void draw_instances_indexed(draw_mode mode, index_type type, size_t start, size_t count, size_t instances) noexcept;

		void blit_to_surface(framebuffer &buffer, glm::ivec2 src_p1, glm::ivec2 src_p2, glm::ivec2 dest_p1, glm::ivec2 dest_p2) noexcept;

	private:
		core::logger gl_logger;
		std::vector<uint32_t> active_texture_bindings;
	};
}

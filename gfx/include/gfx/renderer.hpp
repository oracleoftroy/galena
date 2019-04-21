#pragma once

#include <memory>
#include <glm/glm.hpp>

namespace gfx
{
	namespace imgui
	{
		class imgui_graphics_core;
	}

	class renderer
	{
	public:
		template <typename renderer_core>
		explicit renderer(renderer_core &&core) noexcept;

		void set_viewport(const glm::ivec2 &p, const glm::ivec2 &size) noexcept;
		void set_clear_color(float r, float g, float b, float a) noexcept;
		void clear_color() noexcept;

		std::unique_ptr<imgui::imgui_graphics_core> create_imgui_graphics_core() noexcept;

	private:
		class renderer_impl_base
		{
		public:
			virtual ~renderer_impl_base() noexcept {};
			virtual void set_viewport(const glm::ivec2 &p, const glm::ivec2 &size) noexcept = 0;
			virtual void set_clear_color(float r, float g, float b, float a) noexcept = 0;
			virtual void clear_color() noexcept = 0;
			virtual std::unique_ptr<imgui::imgui_graphics_core> create_imgui_graphics_core() noexcept = 0;
		};

		template <typename renderer_core>
		class renderer_impl final : public renderer_impl_base
		{
		public:
			renderer_impl(renderer_core &&core) noexcept;
			void set_viewport(const glm::ivec2 &p, const glm::ivec2 &size) noexcept override;
			void set_clear_color(float r, float g, float b, float a) noexcept override;
			void clear_color() noexcept override;

			std::unique_ptr<imgui::imgui_graphics_core> create_imgui_graphics_core() noexcept;

		private:
			renderer_core core;
		};

		std::unique_ptr<renderer_impl_base> base;
	};

	template <typename renderer_core>
	renderer::renderer(renderer_core &&core) noexcept
		: base(std::make_unique<renderer_impl<renderer_core>>(std::move(core)))
	{
	}

	template <typename renderer_core>
	renderer::renderer_impl<renderer_core>::renderer_impl(renderer_core &&core) noexcept
		: core(std::move(core))
	{
	}

	template <typename renderer_core>
	void renderer::renderer_impl<renderer_core>::set_viewport(const glm::ivec2 &p, const glm::ivec2 &size) noexcept
	{
		core_set_viewport(core, p, size);
	}

	template <typename renderer_core>
	void renderer::renderer_impl<renderer_core>::set_clear_color(float r, float g, float b, float a) noexcept
	{
		core_set_clear_color(core, r, g, b, a);
	}

	template <typename renderer_core>
	void renderer::renderer_impl<renderer_core>::clear_color() noexcept
	{
		core_clear_color(core);
	}

	template <typename renderer_core>
	std::unique_ptr<imgui::imgui_graphics_core> renderer::renderer_impl<renderer_core>::create_imgui_graphics_core() noexcept
	{
		return core_create_imgui_graphics_core(core);
	}
}

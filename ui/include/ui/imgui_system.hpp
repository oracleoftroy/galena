#pragma once

namespace ui
{
	class platform;
	class opengl_context;
}

struct ImGuiContext;

namespace ui::imgui
{
	// manages the core imgui and platform specific implementation. Doesn't provide the rendering implementation
	class imgui_system
	{
	public:
		explicit imgui_system(const opengl_context &context) noexcept;
		~imgui_system();

		void new_frame() noexcept;
		void render() noexcept;

		imgui_system(imgui_system &&other) noexcept;
		imgui_system &operator=(imgui_system &&other) noexcept;
		imgui_system(const imgui_system &other) noexcept = delete;
		imgui_system &operator=(const imgui_system &other) noexcept = delete;

	private:
		ImGuiContext *context;
		void *window;
	};
}

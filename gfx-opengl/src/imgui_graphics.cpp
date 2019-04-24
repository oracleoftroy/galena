#include "imgui_graphics.hpp"

#include <imgui.h>
#include <imgui_impl_opengl3.h>

namespace gfx::gl::imgui
{
	imgui_graphics::imgui_graphics() noexcept
	{
		// TODO: make this 320 es to match requested gles version
		ImGui_ImplOpenGL3_Init("#version 300 es");
	}

	imgui_graphics::~imgui_graphics() noexcept
	{
		ImGui_ImplOpenGL3_Shutdown();
	}

	void imgui_graphics::new_frame() noexcept
	{
		ImGui_ImplOpenGL3_NewFrame();
	}

	void imgui_graphics::render() noexcept
	{
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
}

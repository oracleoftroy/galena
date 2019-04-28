#include "opengl_imgui_graphics.hpp"

#include <imgui.h>
#include <imgui_impl_opengl3.h>

namespace gfx::gl::imgui
{
	opengl_imgui_graphics::opengl_imgui_graphics() noexcept
	{
		// Example imgui implementation doesn't recognize gles shader versions greater than 300
		ImGui_ImplOpenGL3_Init("#version 300 es");
	}

	opengl_imgui_graphics::~opengl_imgui_graphics()
	{
		ImGui_ImplOpenGL3_Shutdown();
	}

	void opengl_imgui_graphics::new_frame() noexcept
	{
		ImGui_ImplOpenGL3_NewFrame();
	}

	void opengl_imgui_graphics::render() noexcept
	{
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
}

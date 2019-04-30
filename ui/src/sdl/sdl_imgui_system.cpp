#include <ui/imgui_system.hpp>

#include <utility>
#include <imgui.h>
#include "imgui_impl_sdl.h"
#include <SDL2/SDL_events.h>

#include "../log.hpp"
#include "sdl_opengl_context.hpp"

namespace ui::imgui
{
	namespace
	{
		// hack, but imgui is a giant global variable hack already, so if anything works, this ought to work too
		static int imgui_wants_events;

		static void imgui_destroy(ImGuiContext *context) noexcept
		{
			// given that imgui does lots of global things, don't delete the context if
			// it is null to prevent deleting some random context that is currently set
			if (context != nullptr)
			{
				ImGui::DestroyContext(context);
				--imgui_wants_events;
				if (imgui_wants_events < 0)
					LOG_ERROR("imgui destroyed too many times!");
			}
		}
	}

	imgui_system::imgui_system(const opengl_context &gl) noexcept
		: context(nullptr), window(gl.data->window)
	{
		LOG_INFO("Initializing ImGui");

		IMGUI_CHECKVERSION();
		context = ImGui::CreateContext();
		//auto &io = ImGui::GetIO();
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsClassic();
		//ImGui::StyleColorsLight();

		ImGui_ImplSDL2_InitForOpenGL(gl.data->window, gl.data->context);
		++imgui_wants_events;
	}

	imgui_system::~imgui_system()
	{
		imgui_destroy(context);
	}

	imgui_system::imgui_system(imgui_system &&other) noexcept
		: context(std::exchange(other.context, nullptr)), window(std::exchange(other.window, nullptr))
	{
	}

	imgui_system &imgui_system::operator=(imgui_system &&other) noexcept
	{
		imgui_system old(std::move(*this));
		context = std::exchange(other.context, nullptr);
		window = std::exchange(other.window, nullptr);
		return *this;
	}

	void imgui_system::new_frame() noexcept
	{
		ImGui::SetCurrentContext(context);
		ImGui_ImplSDL2_NewFrame(static_cast<SDL_Window *>(window));
		ImGui::NewFrame();
	}

	void imgui_system::render() noexcept
	{
		ImGui::Render();
	}

	bool imgui_dispatch_events(SDL_Event *event) noexcept
	{
		if (imgui_wants_events > 0)
		{
			ImGui_ImplSDL2_ProcessEvent(event);

			auto &io = ImGui::GetIO();
			switch (event->type)
			{
			default: return false;
			case SDL_KEYDOWN:
			case SDL_KEYUP:
			case SDL_TEXTEDITING:
			case SDL_TEXTINPUT:
			case SDL_KEYMAPCHANGED:
				return io.WantCaptureKeyboard;

			case SDL_MOUSEMOTION:
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
			case SDL_MOUSEWHEEL:
				return io.WantCaptureMouse;
			}
		}
		return false;
	}
}

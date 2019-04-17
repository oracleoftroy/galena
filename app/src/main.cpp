#include <ui/clock.hpp>
#include <ui/config_opengl.hpp>
#include <ui/keyboard.hpp>
#include <ui/events.hpp>
#include <ui/opengl_context.hpp>
#include <ui/platform.hpp>
#include <ui/window.hpp>
#include <ui/imgui_system.hpp>

#include "frame_metrics.hpp"
#include "log.hpp"

using namespace std::chrono_literals;

// TODO: REMOVE ME and implement in renderer
#include "glad/glad.h"
#pragma comment(lib, "opengl32.lib")

#include <imgui.h>
#include "imgui_impl_opengl3.h"
//////////////////

template <typename T>
struct event_dispatch : T
{
	void operator()(const ui::event &e) noexcept
	{
		T &h = *this;
		if (e.type == ui::event_type::keyboard)
			h(static_cast<const ui::keyboard_event &>(e));
		else if (e.type == ui::event_type::mouse_move)
			h(static_cast<const ui::mouse_move_event &>(e));
		else if (e.type == ui::event_type::mouse_button)
			h(static_cast<const ui::mouse_button_event &>(e));
		else if (e.type == ui::event_type::mouse_scroll)
			h(static_cast<const ui::mouse_scroll_event &>(e));
		else if (e.type == ui::event_type::controller_analog)
			h(static_cast<const ui::controller_analog_event &>(e));
		else if (e.type == ui::event_type::controller_button)
			h(static_cast<const ui::controller_button_event &>(e));
		else if (e.type == ui::event_type::text_input)
			h(static_cast<const ui::text_input_event &>(e));
	}
};

struct event_handler
{
	void operator()(const ui::keyboard_event &e) noexcept
	{
		LOG_CRITICAL("keyboard {0} modifiers: {1}", e.key, e.mods);
	}

	void operator()(const ui::mouse_move_event &e) noexcept
	{
		LOG_CRITICAL("mouse moved {0}, {1}", e.position.x, e.position.y);
	}

	void operator()(const ui::mouse_button_event &e) noexcept
	{
		LOG_CRITICAL("mouse button {0}", e.button);
	}

	void operator()(const ui::mouse_scroll_event &e) noexcept
	{
		LOG_CRITICAL("mouse scroll {0}", e.delta.y);
	}

	void operator()(const ui::controller_analog_event &e) noexcept
	{
		LOG_CRITICAL("controller stick {0}", e.value);
	}

	void operator()(const ui::controller_button_event &e) noexcept
	{
		LOG_CRITICAL("controller button {0}", (int)e.button);
	}

	void operator()(const ui::text_input_event &e) noexcept
	{
		LOG_CRITICAL("text input {0}", e.text);
	}
};

class imgui
{
public:
	imgui(ui::opengl_context &context) : system(context)
	{
		ImGui_ImplOpenGL3_Init("#version 300 es");
	}

	~imgui()
	{
		ImGui_ImplOpenGL3_Shutdown();
	}

	void new_frame() noexcept
	{
		ImGui_ImplOpenGL3_NewFrame();
		system.new_frame();
	}

	void render() noexcept
	{
		system.render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	imgui(imgui &&other) noexcept = delete;
	imgui &operator=(imgui &&other) noexcept = delete;
	imgui(const imgui &other) noexcept = delete;
	imgui &operator=(const imgui &other) noexcept = delete;

private:
	ui::imgui::imgui_system system;
};

std::array<float, 60 * 3> frame_hist{{0}};
size_t frame_hist_pos = 0;

static void fps_overlay(bool *show, float ft)
{
	const float margin = 2.0f;
	ImGuiIO &io = ImGui::GetIO();

	frame_hist[frame_hist_pos++] = ft;
	frame_hist_pos %= frame_hist.size();

	ImGui::SetNextWindowPos(ImVec2(margin, margin), ImGuiCond_Always, ImVec2(0.0f, 0.0f));
	ImGui::SetNextWindowBgAlpha(0.35f);

	if (ImGui::Begin("FPS overlay", show, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration | /*ImGuiWindowFlags_AlwaysAutoResize |*/ ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav))
	{
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
		ImGui::Separator();
		if (ImGui::IsMousePosValid())
			ImGui::Text("Mouse Position: (%.1f,%.1f)", io.MousePos.x, io.MousePos.y);
		else
			ImGui::Text("Mouse Position: <invalid>");

		ImGui::PlotHistogram("Frame Time", frame_hist.data(), (int)frame_hist.size(), (int)frame_hist_pos, "Frame Time", 0.0f, 1.0f / 15.0f, ImVec2(ImGui::GetWindowSize().x - margin * 2, 60));
	}
	ImGui::End();
}

int main(int argc, char* argv[])
{
	LOG_INFO("Initializing...");
	LOG_DEBUG("args: {0}", fmt::join(argv, argv + argc, " "));

	auto platform = ui::platform::create();
	auto window = platform.create_window("Test window", 1280, 720, ui::window_mode::windowed, ui::gfx_engine::opengl);
	LOG_TRACE("window reports size of ({0}, {1})", window.size().x, window.size().y);

	ui::config_opengl config;
	config.context_profile = ui::gl_context_profile::es;
	config.context_major_version = 3;
	config.context_minor_version = 2;

	auto gl_context = window.opengl_create_context(config);
	gladLoadGLES2Loader(gl_context.get_load_proc());

	LOG_INFO("OpenGL version: {0}", glGetString(GL_VERSION));
	LOG_INFO("OpenGL vendor: {0}", glGetString(GL_VENDOR));
	LOG_INFO("OpenGL renderer: {0}", glGetString(GL_RENDERER));
	LOG_INFO("OpenGL shader version: {0}", glGetString(GL_SHADING_LANGUAGE_VERSION));
//	LOG_INFO("OpenGL shader extensions: {0}", glGetString(GL_EXTENSIONS));

	imgui imgui_system(gl_context);

	ui::clock::duration target_frame_rate = 1.0s / 60.0;
	app::frame_metrics metrics(target_frame_rate);
	ui::clock clock(target_frame_rate);

	event_dispatch<event_handler> handler;
	platform.attach_event_listener(handler);

	bool show_demo = true;
	bool show_fps_overlay = true;

	while (platform.dispatch_events())
	{
		auto frame_duration = clock.update();
		metrics.update(frame_duration);

		// tick game at a steady interval
		while (clock.use_time_slice())
		{
//			LOG_TRACE(clock.time_slice.count());
			// game.tick(clock.time_slice);
		}

		// render
		// game.render(renderer);

		// TODO: REMOVE ME!!!!
		glClearColor(.5f, .8f, .2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		imgui_system.new_frame();
		if (show_demo)
			ImGui::ShowDemoWindow(&show_demo);
		if (show_fps_overlay)
			fps_overlay(&show_fps_overlay, (float)frame_duration.count());
		imgui_system.render();

		gl_context.present();
		//////////////////////
	}

	LOG_INFO("Exiting...");
}

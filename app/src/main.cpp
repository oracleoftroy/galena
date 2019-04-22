#include <ui/clock.hpp>
#include <ui/config_opengl.hpp>
#include <ui/keyboard.hpp>
#include <ui/events.hpp>
#include <ui/opengl_context.hpp>
#include <ui/platform.hpp>
#include <ui/window.hpp>
#include <ui/imgui_system.hpp>

#include <gfx/imgui_graphics.hpp>
#include <gfx/renderer.hpp>
#include <gfx/gl/opengl_renderer_core.hpp>

#include <glm/gtc/type_ptr.hpp>

#include "frame_metrics.hpp"
#include "imgui.hpp"
#include "log.hpp"

#include <imgui.h>

using namespace std::chrono_literals;

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

// TODO: move histogram to frame_metrics
std::array<float, 60 * 3> frame_hist{{0}};
size_t frame_hist_pos = 0;

static void fps_overlay(bool *show)
{
	const float margin = 2.0f;
	ImGuiIO &io = ImGui::GetIO();

	frame_hist[frame_hist_pos++] = io.DeltaTime;
	frame_hist_pos %= frame_hist.size();

	ImGui::SetNextWindowPos(ImVec2(margin, margin), ImGuiCond_Always, ImVec2(0.0f, 0.0f));
	ImGui::SetNextWindowBgAlpha(0.35f);

	if (ImGui::Begin("FPS overlay", show, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav))
	{
		ImGui::Text("Frame time average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
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
	event_dispatch<event_handler> handler;
	platform.attach_event_listener(handler);

	auto window = platform.create_window("Test window", 1280, 720, ui::window_mode::windowed, ui::gfx_engine::opengl);
	auto window_size = window.size();
	LOG_TRACE("window reports size of ({0}, {1})", window_size.x, window_size.y);

	ui::config_opengl config;
	config.context_profile = ui::gl_context_profile::es;
	config.context_major_version = 3;
	config.context_minor_version = 2;

	auto opengl_context = window.opengl_create_context(config);
	auto renderer = gfx::gl::create_opengl_renderer(opengl_context);
	app::imgui imgui(opengl_context, renderer);

	// consider removing this or moving the ini file, but for now, disable completely
	ImGui::GetIO().IniFilename = nullptr;

	ui::clock::duration target_frame_rate = 1.0s / 60.0;
	app::frame_metrics metrics(target_frame_rate);

	glm::vec4 clear_color(0.384f, 0.761f, 0.984f, 1.0f);
	renderer.set_clear_color(clear_color.r, clear_color.g, clear_color.b, clear_color.a);

	auto size = opengl_context.drawable_size();

	bool show_fps_overlay = true;
	bool show_opengl_settings = true;

	int vsync_play = 1;

	ui::clock clock(target_frame_rate);
	while (platform.dispatch_events())
	{
		auto frame_duration = clock.update();
		metrics.update(frame_duration);

		// tick game at a steady interval
		while (clock.use_time_slice())
		{
			// game.tick(clock.time_slice);
		}

		// render
		renderer.clear_color();
		// game.render(renderer);

		imgui.new_frame();

		if (show_fps_overlay)
			fps_overlay(&show_fps_overlay);

		if (show_opengl_settings)
		{
			ImGui::SetNextWindowPos(ImVec2(size.x - 2.0f, 2.0f), ImGuiCond_Always, ImVec2(1.0f, 0.0f));
			ImGui::Begin("OpenGL settings", &show_opengl_settings, ImGuiWindowFlags_AlwaysAutoResize);

			if (ImGui::SliderInt("VSync control", &vsync_play, -4, 4))
				LOG_INFO("Setting vsync: {}", opengl_context.set_swap_interval(vsync_play));

			if (ImGui::ColorEdit3("Clear color", glm::value_ptr(clear_color)))
				renderer.set_clear_color(clear_color.r, clear_color.g, clear_color.b, clear_color.a);

			ImGui::End();
		}

		imgui.render();

		opengl_context.present();
	}

	LOG_INFO("Exiting...");
}

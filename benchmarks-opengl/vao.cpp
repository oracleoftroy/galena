#include <benchmark/benchmark.h>

#define LOGGER_IMPL the_logger
#include <core/log_macros.hpp>
#include <ui/clock.hpp>
#include <ui/config_opengl.hpp>
#include <ui/platform.hpp>
#include <ui/window.hpp>

#include <glad/glad.h>
#include <ui/opengl_context.hpp>

#pragma warning (push)
#pragma warning (disable: 4127)
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#pragma warning (pop)

core::logger the_logger = core::register_logger("vao benchmark");

bool clear_errors()
{
	while (glGetError() != GL_NO_ERROR);
	return true;
}

//#include <intrin.h>

#define GL(x) do {clear_errors() && (x); if (glGetError() != GL_NO_ERROR) __debugbreak(); } while(0)
#define CHECK_GL do { if (glGetError()) __debugbreak(); } while(0)

static void APIENTRY on_gl_debug_message([[maybe_unused]] GLenum source, [[maybe_unused]] GLenum type, [[maybe_unused]] GLuint id, [[maybe_unused]] GLenum severity, [[maybe_unused]] GLsizei length, [[maybe_unused]] const GLchar *message, [[maybe_unused]] const void *user_data)
{
	LOG_WARN("OpenGL MSG: {0}", message);
}

struct setup
{
	setup()
	{
		core::default_log_level(core::log_level::critical);
		platform.attach_event_listener([](const auto &) {});
		window = platform.create_window("benchmark", 1280, 720, ui::window_mode::windowed, ui::gfx_engine::opengl);

		ui::config_opengl config;
		config.context_profile = ui::opengl_profile::es;
		config.major_version = 3;
		config.minor_version = 2;
		context = window.opengl_create_context(config);

		// disable vsync for benchmark
		context.set_swap_interval(0);

		gladLoadGLES2Loader(context.get_load_proc());

		glDebugMessageCallback(on_gl_debug_message, nullptr);
		//glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, nullptr, GL_FALSE);
		//glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_LOW, 0, nullptr, GL_TRUE);
		//glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_MEDIUM, 0, nullptr, GL_TRUE);
		//glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_HIGH, 0, nullptr, GL_TRUE);
		//glEnable(GL_DEBUG_OUTPUT);
		//glDisable(GL_DEBUG_OUTPUT_SYNCHRONOUS);

	}

	ui::platform platform;
	ui::window window;
	ui::opengl_context context;
};

struct vertex
{
	glm::vec3 position;
	glm::vec3 color;
};

const char vertex_shader[] = R"SHADER(
#version 320 es

layout (location = 0) in highp vec4 in_position;
layout (location = 1) in lowp vec4 in_color;

layout(location = 0) uniform mat4 model_view;

out lowp vec4 color;

void main()
{
	gl_Position = model_view * in_position;
	color = in_color;
}
)SHADER";

const char fragment_shader[] = R"SHADER(
#version 320 es

in lowp vec4 color;

out lowp vec4 out_color;

void main()
{
	out_color = color;
}
)SHADER";

GLuint compile_shader(GLenum type, const char *src)
{
	GLuint program = glCreateShaderProgramv(type, 1, &src);

	GLint success = 0;
	glGetProgramiv(program, GL_LINK_STATUS, &success);

	if (!success)
		throw 1;

	return program;
}

vertex cube_v[]
{
	{{-0.5f, -0.5f, -0.5f}, {0.0f, 0.0f, 0.0f}},
	{{0.5f, -0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}},
	{{-0.5f, 0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
	{{-0.5f, -0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}},
	{{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f, 0.0f}},
	{{0.5f, -0.5f, 0.5f}, {1.0f, 0.0f, 1.0f}},
	{{-0.5f, 0.5f, 0.5f}, {0.0f, 1.0f, 1.0f}},
	{{0.5f, 0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}},
};

glm::vec3 cube_poss[]
{
	{-0.5f, -0.5f, -0.5f},
	{0.5f, -0.5f, -0.5f},
	{-0.5f, 0.5f, -0.5f},
	{-0.5f, -0.5f, 0.5f},
	{0.5f, 0.5f, -0.5f},
	{0.5f, -0.5f, 0.5f},
	{-0.5f, 0.5f, 0.5f},
	{0.5f, 0.5f, 0.5f},
};

glm::vec3 cube_colors[]
{
	{0.0f, 0.0f, 0.0f},
	{1.0f, 0.0f, 0.0f},
	{0.0f, 1.0f, 0.0f},
	{0.0f, 0.0f, 1.0f},
	{1.0f, 1.0f, 0.0f},
	{1.0f, 0.0f, 1.0f},
	{0.0f, 1.0f, 1.0f},
	{1.0f, 1.0f, 1.0f},
};

short cube_idx[]
{
	0, 2, 4,
	0, 4, 1,
	1, 4, 7,
	1, 7, 5,
	5, 7, 6,
	5, 6, 3,
	3, 6, 2,
	3, 2, 0,
	6, 4, 2,
	6, 7, 4,
	1, 3, 0,
	1, 5, 3,
};

static void proper_vao(benchmark::State &state)
{
	setup data;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearDepthf(1.0);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);

	// Create VBO for AOV vbo
	GLuint vb, ib;
	// create vertex buffer
	glGenBuffers(1, &vb);
	glBindBuffer(GL_ARRAY_BUFFER, vb);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_v), &cube_v, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// create index buffer
	glGenBuffers(1, &ib);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_idx), &cube_idx, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// create vao
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glEnableVertexAttribArray(0);
	glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, offsetof(vertex, vertex::position));
	glVertexAttribBinding(0, 0);

	glEnableVertexAttribArray(1);
	glVertexAttribFormat(1, 3, GL_FLOAT, GL_FALSE, offsetof(vertex, vertex::color));
	glVertexAttribBinding(1, 0);

	glBindVertexBuffer(0, vb, 0, sizeof(vertex));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
	glBindVertexArray(0);

	// done creating vao, unbind buffers
	//glBindVertexBuffer(0, 0, 0, sizeof(vertex));
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	// DONE: Create VBO for AOV vbo
	///////////////////////////////////////////////////////////////

	// Create VBO for VOA vbo
	GLuint pos_buf, color_buf;

	// create vertex buffer for positions
	glGenBuffers(1, &pos_buf);
	glBindBuffer(GL_ARRAY_BUFFER, pos_buf);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_poss), &cube_poss, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// create vertex buffer for colors
	glGenBuffers(1, &color_buf);
	glBindBuffer(GL_ARRAY_BUFFER, color_buf);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_colors), &cube_colors, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// create vao
	GLuint voa_vao;
	glGenVertexArrays(1, &voa_vao);
	glBindVertexArray(voa_vao);

	glEnableVertexAttribArray(0);
	glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
	glVertexAttribBinding(0, 0);

	glEnableVertexAttribArray(1);
	glVertexAttribFormat(1, 3, GL_FLOAT, GL_FALSE, 0);
	glVertexAttribBinding(1, 1);

	glBindVertexBuffer(0, pos_buf, 0, sizeof(cube_poss[0]));
	glBindVertexBuffer(1, color_buf, 0, sizeof(cube_colors[0]));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
	glBindVertexArray(0);

	// done creating vao, unbind buffers
	//glBindVertexBuffer(0, 0, 0, sizeof(cube_poss[0]));
	//glBindVertexBuffer(1, 0, 0, sizeof(cube_colors[0]));
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	// DONE: Create VBO for VOA vbo
	///////////////////////////////////////////////////////////////

	GLuint vertex = compile_shader(GL_VERTEX_SHADER, vertex_shader);
	GLuint fragment = compile_shader(GL_FRAGMENT_SHADER, fragment_shader);

	GLuint pipeline;
	glGenProgramPipelines(1, &pipeline);
	glUseProgramStages(pipeline, GL_VERTEX_SHADER_BIT, vertex);
	glUseProgramStages(pipeline, GL_FRAGMENT_SHADER_BIT, fragment);

	auto size = data.context.drawable_size();

	glm::vec3 rot(2.0f, 3.0f, 5.0f);
	glm::vec3 rot2(10.0f, 3.0f, 5.0f);

//	auto projection = glm::perspective(90.0f, static_cast<float>(size.x) / size.y, 1.0f, 100.0f);
	auto projection = glm::perspectiveFov(45.0f, static_cast<float>(size.x), static_cast<float>(size.y), 1.0f, 100.0f);
	auto camera = glm::translate(glm::identity<glm::mat4>(), glm::vec3(0.0f, 0.0f, -70.0f));
	auto proj_view = projection * camera;

	auto model_vao1 = glm::scale(glm::identity<glm::mat4>(), glm::vec3(10.0f, 10.0f, 10.0f));
	model_vao1 = glm::translate(model_vao1, glm::vec3(-2.0f, -2.0f, 0.0f));

	auto model_vao2 = glm::scale(glm::identity<glm::mat4>(), glm::vec3(10.0f, 10.0f, 10.0f));;
	model_vao2 = glm::translate(model_vao2, glm::vec3(2.0f, 2.0f, 0.0f));

	float angle = 3.0f;
	ui::clock clock(ui::clock::duration(1.0 / 60.0));

	for (auto _ : state)
	{
		auto d = clock.update();
		[[maybe_unused]] auto b = data.platform.dispatch_events();

		while (clock.use_time_slice())
		{
//			model_vao1 = glm::translate(model_vao1, glm::vec3(-2.0f, -2.0f, 0.0f));
			model_vao1 = glm::rotate(model_vao1, static_cast<float>(angle * clock.time_slice.count()), rot2);

			model_vao2 = glm::rotate(model_vao2, static_cast<float>(angle * clock.time_slice.count()), rot2);
//			model_vao2 = glm::translate(model_vao2, glm::vec3(2.0f, 2.0f, 0.0f));
		}
		auto mvp1 = proj_view * model_vao1;
		auto mvp2 = proj_view * model_vao2;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// set up vao
		// set up shader
		glBindProgramPipeline(pipeline);

		glProgramUniformMatrix4fv(vertex, 0, 1, GL_FALSE, glm::value_ptr(mvp1));
		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, sizeof(cube_idx) / sizeof(*cube_idx), GL_UNSIGNED_SHORT, nullptr);

		glProgramUniformMatrix4fv(vertex, 0, 1, GL_FALSE, glm::value_ptr(mvp2));
		glBindVertexArray(voa_vao);
		glDrawElements(GL_TRIANGLES, sizeof(cube_idx) / sizeof(*cube_idx), GL_UNSIGNED_SHORT, nullptr);

		data.context.present();
	}

	glDeleteProgramPipelines(1, &pipeline);
	glDeleteProgram(fragment);
	glDeleteProgram(vertex);
	glDeleteVertexArrays(1, &voa_vao);
	glDeleteBuffers(1, &pos_buf);
	glDeleteBuffers(1, &color_buf);
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &ib);
	glDeleteBuffers(1, &vb);
}

BENCHMARK(proper_vao);

static void single_vao(benchmark::State &state)
{
	setup data;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearDepthf(1.0);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);

	// Create VBO for AOV vbo
	GLuint vb, ib;
	// create vertex buffer
	glGenBuffers(1, &vb);
	glBindBuffer(GL_ARRAY_BUFFER, vb);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_v), &cube_v, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// create index buffer
	glGenBuffers(1, &ib);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_idx), &cube_idx, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// create vao
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Create VBO for VOA vbo
	GLuint pos_buf, color_buf;

	// create vertex buffer for positions
	glGenBuffers(1, &pos_buf);
	glBindBuffer(GL_ARRAY_BUFFER, pos_buf);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_poss), &cube_poss, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// create vertex buffer for colors
	glGenBuffers(1, &color_buf);
	glBindBuffer(GL_ARRAY_BUFFER, color_buf);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_colors), &cube_colors, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint vertex = compile_shader(GL_VERTEX_SHADER, vertex_shader);
	GLuint fragment = compile_shader(GL_FRAGMENT_SHADER, fragment_shader);

	GLuint pipeline;
	glGenProgramPipelines(1, &pipeline);
	glUseProgramStages(pipeline, GL_VERTEX_SHADER_BIT, vertex);
	glUseProgramStages(pipeline, GL_FRAGMENT_SHADER_BIT, fragment);

	auto size = data.context.drawable_size();

	glm::vec3 rot(2.0f, 3.0f, 5.0f);
	glm::vec3 rot2(10.0f, 3.0f, 5.0f);

	//	auto projection = glm::perspective(90.0f, static_cast<float>(size.x) / size.y, 1.0f, 100.0f);
	auto projection = glm::perspectiveFov(45.0f, static_cast<float>(size.x), static_cast<float>(size.y), 1.0f, 100.0f);
	auto camera = glm::translate(glm::identity<glm::mat4>(), glm::vec3(0.0f, 0.0f, -70.0f));
	auto proj_view = projection * camera;

	auto model_vao1 = glm::scale(glm::identity<glm::mat4>(), glm::vec3(10.0f, 10.0f, 10.0f));
	model_vao1 = glm::translate(model_vao1, glm::vec3(-2.0f, -2.0f, 0.0f));

	auto model_vao2 = glm::scale(glm::identity<glm::mat4>(), glm::vec3(10.0f, 10.0f, 10.0f));;
	model_vao2 = glm::translate(model_vao2, glm::vec3(2.0f, 2.0f, 0.0f));

	float angle = 3.0f;
	ui::clock clock(ui::clock::duration(1.0 / 60.0));

	for (auto _ : state)
	{
		auto d = clock.update();
		[[maybe_unused]] bool b = data.platform.dispatch_events();

		while (clock.use_time_slice())
		{
			//			model_vao1 = glm::translate(model_vao1, glm::vec3(-2.0f, -2.0f, 0.0f));
			model_vao1 = glm::rotate(model_vao1, static_cast<float>(angle * clock.time_slice.count()), rot);

			model_vao2 = glm::rotate(model_vao2, static_cast<float>(angle * clock.time_slice.count()), rot2);
			//			model_vao2 = glm::translate(model_vao2, glm::vec3(2.0f, 2.0f, 0.0f));
		}
		auto mvp1 = proj_view * model_vao1;
		auto mvp2 = proj_view * model_vao2;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// set up vao
		// set up shader
		glBindProgramPipeline(pipeline);

		////////////
		glProgramUniformMatrix4fv(vertex, 0, 1, GL_FALSE, glm::value_ptr(mvp1));

		glBindVertexBuffer(0, vb, 0, sizeof(cube_v[0]));

		glEnableVertexAttribArray(0);
		glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, offsetof(::vertex, vertex::position));
		glVertexAttribBinding(0, 0);
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(::vertex), (void *)offsetof(::vertex, vertex::position));

		glEnableVertexAttribArray(1);
		glVertexAttribFormat(1, 3, GL_FLOAT, GL_FALSE, offsetof(::vertex, vertex::color));
		glVertexAttribBinding(1, 0);
//		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(::vertex), (void *)offsetof(::vertex, vertex::color));

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
		glDrawElements(GL_TRIANGLES, sizeof(cube_idx) / sizeof(*cube_idx), GL_UNSIGNED_SHORT, nullptr);
		////////////////

		////////////////////
		glProgramUniformMatrix4fv(vertex, 0, 1, GL_FALSE, glm::value_ptr(mvp2));

		glEnableVertexAttribArray(0);
		glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
		glVertexAttribBinding(0, 0);

		glEnableVertexAttribArray(1);
		glVertexAttribFormat(1, 3, GL_FLOAT, GL_FALSE, 0);
		glVertexAttribBinding(1, 1);

		glBindVertexBuffer(0, pos_buf, 0, sizeof(cube_poss[0]));
		glBindVertexBuffer(1, color_buf, 0, sizeof(cube_colors[0]));

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib);
		glDrawElements(GL_TRIANGLES, sizeof(cube_idx) / sizeof(*cube_idx), GL_UNSIGNED_SHORT, nullptr);
		//////////////////

		data.context.present();
	}

	glDeleteProgramPipelines(1, &pipeline);
	glDeleteProgram(fragment);
	glDeleteProgram(vertex);
	glDeleteBuffers(1, &pos_buf);
	glDeleteBuffers(1, &color_buf);
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &ib);
	glDeleteBuffers(1, &vb);
}

BENCHMARK(single_vao);

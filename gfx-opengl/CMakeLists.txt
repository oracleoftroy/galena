add_library(gfx-opengl
	"include/gfx/gl/opengl_renderer_core.hpp"

	"vendor/glad/include/glad/glad.h"
	"vendor/glad/include/KHR/khrplatform.h"
	"vendor/glad/src/glad.c"
	"vendor/imgui/imgui_impl_opengl3.cpp"
	"vendor/imgui/imgui_impl_opengl3.h"

	"src/adapters/opengl_buffer_core.cpp"
	"src/adapters/opengl_buffer_core.hpp"
	"src/adapters/opengl_imgui_graphics.cpp"
	"src/adapters/opengl_imgui_graphics.hpp"
	"src/adapters/opengl_mesh_core.cpp"
	"src/adapters/opengl_mesh_core.hpp"
	"src/adapters/opengl_pipeline_core.cpp"
	"src/adapters/opengl_pipeline_core.hpp"
	"src/adapters/opengl_program_core.cpp"
	"src/adapters/opengl_program_core.hpp"
	"src/adapters/opengl_renderer_core.cpp"
	"src/buffer.cpp"
	"src/buffer.hpp"
	"src/framebuffer.cpp"
	"src/framebuffer.hpp"
	"src/image.cpp"
	"src/image.hpp"
	"src/log.cpp"
	"src/log.hpp"
	"src/program.cpp"
	"src/program.hpp"
	"src/program_pipeline.cpp"
	"src/program_pipeline.hpp"
	"src/renderbuffer.cpp"
	"src/renderbuffer.hpp"
	"src/renderer.cpp"
	"src/renderer.hpp"
	"src/sampler.cpp"
	"src/sampler.hpp"
#	"src/text_layout.cpp"
#	"src/text_layout.hpp"
	"src/texture.cpp"
	"src/texture.hpp"
	"src/vertex_array_object.cpp"
	"src/vertex_array_object.hpp"
)

target_compile_definitions(gfx-opengl PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLAD)
target_include_directories(gfx-opengl PUBLIC "include")
target_include_directories(gfx-opengl PRIVATE "vendor/glad/include" "vendor/imgui")
target_link_libraries(gfx-opengl PRIVATE core gfx ui)

find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

target_link_libraries(gfx-opengl PRIVATE glm imgui::imgui)

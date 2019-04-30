add_library(gfx
	"include/gfx/buffer.hpp"
	"include/gfx/imgui_graphics.hpp"
	"include/gfx/mesh.hpp"
	"include/gfx/pipeline.hpp"
	"include/gfx/program.hpp"
	"include/gfx/renderer.hpp"
	"src/buffer.cpp"
	"src/log.cpp"
	"src/log.hpp"
	"src/mesh.cpp"
	"src/pipeline.cpp"
	"src/program.cpp"
	"src/renderer.cpp"
)

target_include_directories(gfx PUBLIC "include")
target_link_libraries(gfx PRIVATE core)

find_package(glm CONFIG REQUIRED)
target_link_libraries(gfx PRIVATE glm)

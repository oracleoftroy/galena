add_library(ui
	"include/ui/clock.hpp"
	"include/ui/config_opengl.hpp"
	"include/ui/events.hpp"
	"include/ui/imgui_system.hpp"
	"include/ui/keyboard.hpp"
	"include/ui/opengl_context.hpp"
	"include/ui/platform.hpp"
	"include/ui/vulkan_context.hpp"
	"include/ui/window.hpp"
	"src/keyboard.cpp"
	"src/log.cpp"
	"src/log.hpp"
	"src/opengl_context.cpp"
	"src/platform.cpp"
	"src/platform_info.hpp"
	"src/vulkan_context.cpp"
	"src/window.cpp"

	# TODO: add configure option for SDL platform
	"src/sdl/imgui_impl_sdl.cpp"
	"src/sdl/imgui_impl_sdl.h"
	"src/sdl/sdl_dispatch_events.hpp"
	"src/sdl/sdl_imgui_system.cpp"
	"src/sdl/sdl_keyboard.hpp"
	"src/sdl/sdl_opengl_context.cpp"
	"src/sdl/sdl_opengl_context.hpp"
	"src/sdl/sdl_platform.cpp"
	"src/sdl/sdl_platform.hpp"
	"src/sdl/sdl_util.hpp"
	"src/sdl/sdl_vulkan_context.cpp"
	"src/sdl/sdl_vulkan_context.hpp"
	"src/sdl/sdl_window.cpp"
)


if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
	set_property(SOURCE "src/sdl/imgui_impl_sdl.cpp" APPEND PROPERTY COMPILE_OPTIONS "-Wno-conversion;-Wno-implicit-float-conversion")
endif()

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	set_property(SOURCE "src/sdl/imgui_impl_sdl.cpp" APPEND PROPERTY COMPILE_OPTIONS "-Wno-pragma-pack")
endif()

# TODO: UI_PLATFORM should be configured based on configure option
target_compile_definitions(ui PUBLIC "UI_PLATFORM=1")
target_include_directories(ui PUBLIC "include")
target_link_libraries(ui PRIVATE core gfx)

find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)

target_link_libraries(ui PUBLIC glm PRIVATE imgui::imgui SDL2::SDL2 SDL2::SDL2main)

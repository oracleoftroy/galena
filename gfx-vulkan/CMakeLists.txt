add_library(gfx-vulkan
	"include/gfx/vk/vulkan_renderer_core.hpp"
	"src/vulkan_renderer_core.cpp"

	"src/vulkan_imgui_graphics.hpp"
	"src/vulkan_imgui_graphics.cpp"

	"src/log.hpp"
	"src/log.cpp"

	"vendor/imgui/imgui_impl_vulkan.h"
	"vendor/imgui/imgui_impl_vulkan.cpp"

	"vendor/vulkan_dist/include/vulkan_loader.h"
	"vendor/vulkan_dist/src/vulkan_loader.c"
)

if (NOT MSVC)
	set_property(SOURCE vendor/imgui/imgui_impl_vulkan.cpp APPEND PROPERTY COMPILE_OPTIONS -Wno-conversion -Wno-sign-conversion)
endif()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	target_link_libraries(gfx-vulkan PUBLIC stdc++fs)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	#target_link_libraries(gfx-vulkan PUBLIC c++experimental)
	target_link_libraries(gfx-vulkan PUBLIC stdc++fs)
endif()

target_include_directories(gfx-vulkan PRIVATE "vendor/imgui" "vendor/vulkan_dist/include")
target_include_directories(gfx-vulkan PUBLIC "include")
target_link_libraries(gfx-vulkan PRIVATE core gfx ui)

find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

target_link_libraries(gfx-vulkan PUBLIC glm PRIVATE imgui::imgui)

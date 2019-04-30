cmake_minimum_required(VERSION 3.13)
project(galena VERSION 0.0.1)

# newer cmake versions don't include /W3 in MSVC builds by default (should be in cmake 3.15)
# we want to set /W4 and not get "Command line warning D9025: overriding '/W3' with '/W4'"
if (POLICY CMP0092)
	cmake_policy(SET CMP0092 NEW)
elseif (MSVC)
	# remove default warning level from CMAKE_CXX_FLAGS
	string(REGEX REPLACE "/W[0-4]" "" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
	string(REGEX REPLACE "/W[0-4]" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(BUILD_SHARED_LIBS OFF)

#global defines
add_compile_definitions(GLM_FORCE_SILENT_WARNINGS IMGUI_DISABLE_OBSOLETE_FUNCTIONS)

#global compiler options
# enable a good set of warnings
if (MSVC)
	add_compile_options(/W4 /permissive-)
	add_compile_options(/WX)
else()
	add_compile_options(-Wall -Wextra -pedantic -pedantic-errors -Wconversion -Wsign-conversion)
	add_compile_options(-Werror)
endif()

# enable_testing()

add_subdirectory(app)
add_subdirectory(core)
add_subdirectory(ui)
add_subdirectory(gfx)
add_subdirectory(gfx-opengl)

add_subdirectory(benchmarks-opengl)

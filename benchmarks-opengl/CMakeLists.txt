add_executable(benchmarks-opengl
	"main.cpp"
	"indirection.cpp"
	"read_file.cpp"
	"vao.cpp"
	"../gfx-opengl/vendor/glad/src/glad.c"
	"../app/src/opengl_magic.cpp"
)

if (NOT MSVC)
	set_source_files_properties(../gfx-opengl/vendor/glad/src/glad.c PROPERTIES COMPILE_OPTIONS -Wno-pedantic)
endif()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	target_link_libraries(benchmarks-opengl PUBLIC stdc++fs)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	target_link_libraries(benchmarks-opengl PUBLIC c++experimental)
endif()

target_compile_definitions(benchmarks-opengl PRIVATE _CRT_SECURE_NO_WARNINGS)
target_include_directories(benchmarks-opengl PRIVATE "../gfx-opengl/vendor/glad/include")

target_link_libraries(benchmarks-opengl PRIVATE core ui)

find_package(benchmark CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
target_link_libraries(benchmarks-opengl PRIVATE glm  benchmark::benchmark benchmark::benchmark_main)

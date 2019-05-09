include(CheckIPOSupported)
check_ipo_supported(RESULT ltosupported OUTPUT error)

add_executable(galena_app
	"src/main.cpp"
	"src/frame_metrics.hpp"
	"src/imgui.cpp"
	"src/imgui.hpp"
	"src/log.cpp"
	"src/log.hpp"
	"src/opengl_magic.cpp"
	"src/test_app.cpp"
	"src/test_app.hpp"
)

target_link_libraries(galena_app PRIVATE core gfx gfx-opengl ui)

find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

target_link_libraries(galena_app PRIVATE glm imgui::imgui)

if(ltosupported)
	set_target_properties(galena_app PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

add_custom_command(
	TARGET galena_app POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:galena_app>/shaders"

	COMMAND ${CMAKE_COMMAND} -E copy_if_different
		"${CMAKE_CURRENT_SOURCE_DIR}/shaders/vertex.vert"
		"${CMAKE_CURRENT_SOURCE_DIR}/shaders/fragment.frag"
		"$<TARGET_FILE_DIR:galena_app>/shaders"
)
install(FILES shaders/fragment.frag shaders/vertex.vert DESTINATION bin/shaders)

add_library(core
	"include/core/enum_util.hpp"
	"include/core/log_macros.hpp"
	"include/core/log_subsystem.hpp"
	"include/core/preprocessor.hpp"
	"include/core/resource.hpp"
	"src/log_subsystem.cpp"
	"src/log.cpp"
	"src/log.hpp"
)

target_include_directories(core PUBLIC "include")

find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
target_link_libraries(core PUBLIC fmt::fmt fmt::fmt-header-only spdlog::spdlog)

#pragma once

#define LOGGER_IMPL gfx::gl::detail::get_logger()
#include <core/log_macros.hpp>

namespace gfx::gl::detail
{
	core::logger &get_logger();
}

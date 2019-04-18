#pragma once

#define LOGGER_IMPL gfx::detail::get_logger()
#include <core/log_macros.hpp>

namespace gfx::detail
{
	core::logger &get_logger();
}

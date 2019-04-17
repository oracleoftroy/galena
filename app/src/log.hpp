#pragma once

#define LOGGER_IMPL app::detail::get_logger()
#include <core/log_macros.hpp>

namespace app::detail
{
	core::logger &get_logger();
}

#pragma once

#define LOGGER_IMPL core::detail::get_logger()
#include <core/log_macros.hpp>

namespace core::detail
{
	core::logger &get_logger();
}

#pragma once

#define LOGGER_IMPL ui::detail::get_logger()
#include <core/log_macros.hpp>

namespace ui::detail
{
	core::logger& get_logger();
}

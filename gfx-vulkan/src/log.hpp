#pragma once

#define LOGGER_IMPL gfx::vk::detail::get_logger()
#include <core/log_macros.hpp>

namespace gfx::vk::detail
{
	core::logger &get_logger();
}

#include "log.hpp"

namespace gfx::detail
{
	static core::logger logger = core::register_logger("GFX");

	core::logger &get_logger()
	{
		return logger;
	}
}

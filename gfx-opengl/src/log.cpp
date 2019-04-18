#include "log.hpp"

namespace gfx::gl::detail
{
	static core::logger logger = core::register_logger("GFX:GL");

	core::logger &get_logger()
	{
		return logger;
	}
}

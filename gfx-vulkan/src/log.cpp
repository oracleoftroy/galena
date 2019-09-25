#include "log.hpp"

namespace gfx::vk::detail
{
	static core::logger logger = core::register_logger("GFX:VK");

	core::logger &get_logger()
	{
		return logger;
	}
}

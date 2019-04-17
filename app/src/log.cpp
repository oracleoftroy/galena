#include "log.hpp"

namespace app::detail
{
	static core::logger logger = core::register_logger("APP");

	core::logger &get_logger()
	{
		return logger;
	}
}

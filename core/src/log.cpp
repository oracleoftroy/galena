#include "log.hpp"

namespace core::detail
{
	static core::logger logger = core::register_logger("CORE");

	core::logger &get_logger()
	{
		return logger;
	}
}

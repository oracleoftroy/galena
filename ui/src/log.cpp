#include "log.hpp"

namespace ui::detail
{
	static core::logger logger = core::register_logger("UI");

	core::logger& get_logger()
	{
		return logger;
	}
}

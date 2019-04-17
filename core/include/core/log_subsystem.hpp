#pragma once

// TODO: probably want to default to info or warn and only set lower for debug builds
#if !defined(LOG_LEVEL)
#define LOG_LEVEL 0
#endif

#define SPDLOG_ACTIVE_LEVEL LOG_LEVEL
#include <spdlog/spdlog.h>

namespace core
{
	enum class log_level
	{
		trace,
		debug,
		info,
		warn,
		error,
		critical
	};

	using logger = std::shared_ptr<spdlog::logger>;

	void default_log_level(log_level);
	logger register_logger(const std::string& name);
}

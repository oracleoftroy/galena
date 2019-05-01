#include <core/log_subsystem.hpp>

#if defined(_WIN32)
#include <spdlog/sinks/msvc_sink.h>
#endif
#include <spdlog/sinks/stdout_color_sinks.h>

namespace core
{
	static constexpr spdlog::level::level_enum to_spdlog(log_level level)
	{
		return level == log_level::trace ? spdlog::level::trace
			: level == log_level::debug ? spdlog::level::debug
			: level == log_level::info ? spdlog::level::info
			: level == log_level::warn ? spdlog::level::warn
			: level == log_level::error ? spdlog::level::err
			: spdlog::level::critical;
	}

	void default_log_level(log_level level)
	{
		spdlog::set_level(to_spdlog(level));
	}

	logger register_logger(const std::string& name)
	{
		auto logger = spdlog::get(name);
		if (logger)
			return logger;

		logger = spdlog::stdout_color_mt(name);
		
#if defined(_WIN32)
		logger->sinks().emplace_back(std::make_shared<spdlog::sinks::msvc_sink_mt>());
#endif
		return logger;
	}

	struct logger_format
	{
		logger_format()
		{
			spdlog::set_level(static_cast<spdlog::level::level_enum>(LOG_LEVEL));
			spdlog::set_pattern("[%T] [%^%n%$] (%@): %v");
		}
	};
	static logger_format format;
}

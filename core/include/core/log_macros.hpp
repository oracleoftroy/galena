#pragma once

#include <core/log_subsystem.hpp>

#if !defined(LOGGER_IMPL)
#error You must specify your logger implementation before including this file
#endif

#define LOG_SRC_FILE_INFO spdlog::source_loc{SPDLOG_FILE_BASENAME(__FILE__), __LINE__, SPDLOG_FUNCTION}

#define LOG_TRACE(...) SPDLOG_LOGGER_TRACE(LOGGER_IMPL, __VA_ARGS__)
#define LOG_DEBUG(...) SPDLOG_LOGGER_DEBUG(LOGGER_IMPL, __VA_ARGS__)
#define LOG_INFO(...) SPDLOG_LOGGER_INFO(LOGGER_IMPL, __VA_ARGS__)
#define LOG_WARN(...) SPDLOG_LOGGER_WARN(LOGGER_IMPL, __VA_ARGS__)
#define LOG_ERROR(...) SPDLOG_LOGGER_ERROR(LOGGER_IMPL, __VA_ARGS__)
#define LOG_CRITICAL(...) SPDLOG_LOGGER_CRITICAL(LOGGER_IMPL, __VA_ARGS__)

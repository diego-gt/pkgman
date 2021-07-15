#include <iostream>

#include "Delimiter.hpp"
#include "Logger.hpp"
#include "TimeUtils.hpp"

namespace dgt::log {
Logger::Logger()
{
    dgt::fmt::section_header('*', 80, "BEGIN LOGGING");
}

void Logger::error(const std::string& message)
{
    std::cout << prefix_log(LogLevel::Error) << message << "\n";
}

void Logger::warning(const std::string& message)
{
    std::cout << prefix_log(LogLevel::Warning) << message << "\n";
}

void Logger::debug(const std::string& message)
{
    std::cout << prefix_log(LogLevel::Debug) << message << "\n";
}

void Logger::info(const std::string& message)
{
    std::cout << prefix_log(LogLevel::Info) << message << "\n";
}

const std::string Logger::prefix_log(LogLevel level)
{
    std::string level_str;
    switch (level) {
    case LogLevel::Error:
        level_str = "ERROR";
        break;
    case LogLevel::Warning:
        level_str = "WARN";
        break;
    case LogLevel::Debug:
        level_str = "DEBUG";
        break;
    case LogLevel::Info:
        level_str = "INFO";
        break;
    default:
        level_str = "LOG";
        break;
    }

    return "(" + level_str + ")\t[" + dgt::fmt::get_timestamp() + "]:\t";
}
}

#pragma once

#include <string>

namespace pm::log {
enum LogLevel {
    Error,
    Warning,
    Debug,
    Info
};

// TODO(dgt):
// 1. Enable saving logs to a file
// 1.1 (TBD) Implement a queue to keep messages in memory and manage when to dump them to a file.
// 2. Configuration of logging, only display > level
// 2.1 (TBD) Verbosity
// 3. Print messages with custom format

class Logger {
public:
    Logger();
    static void error(const std::string& message);
    [[maybe_unused]] static void warning(const std::string& message);
    static void debug(const std::string& message);
    static void info(const std::string& message);

private:
    static std::string prefix_log(LogLevel level);
};
}

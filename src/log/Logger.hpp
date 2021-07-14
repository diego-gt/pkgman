#pragma once

#include <string>

namespace dgt::log {
enum LogLevel {
    Error,
    Warning,
    Debug,
    Info
};

class Logger {
public:
    Logger();
    void error(const std::string& message);
    void warning(const std::string& message);
    void debug(const std::string& message);
    void info(const std::string& message);

private:
    const std::string prefix_log(LogLevel level);
};
}

#include "Logger.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>

namespace log {
    void Logger::debug(const std::string &message) {
        std::cout << "DEBUG: [";
        print_timestamp();
        std::cout << "]\t" << message << "\n";
    }

    void Logger::print_timestamp() {
        auto time_now = std::chrono::system_clock::now();
        std::time_t time_c = std::chrono::system_clock::to_time_t(time_now);
        std::cout << std::put_time(std::localtime(&time_c), "%F %T");
    }
}
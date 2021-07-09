#pragma once

#include <string>


namespace log {
    class Logger {
    public:
        static void debug(const std::string &message);

    private:
        static void print_timestamp();
    };
}
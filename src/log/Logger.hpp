#pragma once

#include <string>

//#include "Queue.hpp"

namespace dgt::log {
    class Logger {
    public:
		Logger() = default;
        void debug(const std::string &message);
    };
}

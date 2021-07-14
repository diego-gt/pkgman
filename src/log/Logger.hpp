#pragma once

#include <string>

//#include "Queue.hpp"

namespace dgt::log {
class Logger {
public:
    Logger();
    void debug(const std::string& message);
};
}

#include <iostream>

#include "Logger.hpp"
#include "TimeUtils.hpp"

namespace dgt::log {
    void Logger::debug(const std::string &message) {
        std::cout << "DEBUG: [" << 
			dgt::fmt::get_timestamp() << "]:\t" << 
			message << "\n";
    }
}

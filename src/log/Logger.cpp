#include <iostream>

#include "Logger.hpp"
#include "Delimiter.hpp"
#include "TimeUtils.hpp"

namespace dgt::log {
Logger::Logger() {
	dgt::fmt::section_header('*', 80, "BEGIN LOGGING");	
}

void Logger::debug(const std::string& message)
{
    std::cout << "DEBUG: [" << dgt::fmt::get_timestamp() << "]:\t" << message << "\n";
}
}

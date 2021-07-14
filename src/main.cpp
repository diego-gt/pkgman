#include <iostream>

#include "fmt/TimeUtils.hpp"
#include "fmt/Delimiter.hpp"
#include "log/Logger.hpp"

int main()
{
    std::cout << "swu version 0.0.1" << "\n";

    auto lg = dgt::log::Logger();

    lg.debug("Logging...");
	lg.error("Logging...");
	lg.warning("Logging...");
	lg.info("Logging...");

    return 0;
}

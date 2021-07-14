#include <iostream>

#include "fmt/TimeUtils.hpp"
#include "log/Logger.hpp"

int main()
{
    std::cout << "swu version 0.0.1"
              << "\n";

    //dgt::log::Logger lg (2);
    auto lg = dgt::log::Logger();

    lg.debug(dgt::fmt::get_timestamp());
    return 0;
}

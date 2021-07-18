// On Windows, msvc complains about std::localtime being unsecure
// disable this type of warning until a better way of handling
// this is found.
#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <chrono>
#include <ctime>
#include <string>

#include "Timestamp.hpp"

namespace dgt::fmt {
std::string get_timestamp()
{
    std::time_t time_now = std::time(nullptr);
    char result[64];
    // TODO(dgt): review this procedure to be "more secure" for msvc
    std::strftime(result, sizeof result, "%F %T", std::localtime(&time_now));
    return result;
}
}

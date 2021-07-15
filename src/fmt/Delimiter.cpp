#include <iostream>
#include <string>

#include "Delimiter.hpp"

namespace dgt::fmt {
void section_header(char delimiter, unsigned int length, const std::string& section_name)
{
    // NOTE(dgt): Final length will be length - 1 when section_name.size() is odd.
    double padding;

    if (section_name.size() > length) {
        // if section name overflows length, pad with only 2 chars
        padding = 2;
    } else {
        // Take into account the spaces between section name and delimiters
        padding = (length - section_name.size() - 2) / 2;
    }

    const std::string pad_str = std::string(padding, delimiter);
    std::cout << pad_str << " " << section_name << " " << pad_str << "\n";
}
}

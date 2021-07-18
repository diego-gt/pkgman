#pragma once

#include <string>
#include <vector>

#include "Logger.hpp"
#include "Package.hpp"

namespace pm::pkg {
// TODO(dgt): is this really needed?
enum PackageFileFormat {
    PFF_ARCH,
    PFF_DEBIAN
};

class PackageFileParser {
private:
    std::string m_filepath;
    PackageFileFormat m_file_format;
    bool m_is_init = false;
    std::vector<std::string> m_file_content;

public:
    PackageFileParser(const std::string& filepath, PackageFileFormat file_format);
    ~PackageFileParser() = default;

    void init();

    Package parse();
};
}

#include <fstream>
#include <regex>
#include <string>

#include "PackageFileParser.hpp"

namespace pm::pkg {
PackageFileParser::PackageFileParser(const std::string& filepath, PackageFileFormat file_format)
{
    m_filepath = filepath;
    m_file_format = file_format;
}

void PackageFileParser::init()
{
    switch (m_file_format) {
    case PFF_ARCH:
        log::Logger::info("Using <ARCH>-style package file");
        break;
    case PFF_DEBIAN:
        log::Logger::info("Using <DEBIAN>-style package file");
        break;
    }

    std::ifstream pkg_file(m_filepath);
    std::string curr_line;

    // TODO: research if check for is_open is needed or not
    if (!pkg_file.is_open()) {
        log::Logger::error("Package file could not be opened");
        m_is_init = false;
    } else {
        log::Logger::info("Populating package file details.");
        while (std::getline(pkg_file, curr_line)) {
            m_file_content.push_back(curr_line);
        }
        m_is_init = true;
    }

    std::string msg = "Read " + std::to_string(m_file_content.size()) + " lines.";
    log::Logger::debug(msg);
}

Package PackageFileParser::parse()
{
    Package result;

    if (!m_is_init) {
        log::Logger::error("Package file not initialized.");
        return result;
    }

    // regex magic
    const std::regex rx_pkg_name("pkgname=(.*)");
    const std::regex rx_pkg_version("pkgver=(.*)");
    const std::regex rx_pkg_release("pkgrel=(.*)");

    std::smatch matches_name;
    std::smatch matches_version;
    std::smatch matches_release;

    for (const std::string& line : m_file_content) {
        // basic "parsing", this may need a rework

        // Ignore comments
        if (line.starts_with('#') or line.empty()) {
            continue;
        }

        if (std::regex_search(line, matches_name, rx_pkg_name)) {
            log::Logger::info("Found match for package name...");

            std::string _name = matches_name[1].str();

            result.set_name(_name);
            continue;
        }

        if (std::regex_search(line, matches_version, rx_pkg_version)) {
            log::Logger::info("Found match for package version...");

            std::string _version = matches_version[1].str();

            result.set_version(std::stof(_version));
            continue;
        }

        if (std::regex_search(line, matches_release, rx_pkg_release)) {
            log::Logger::info("Found match for package release...");
            std::string _release = matches_release[1].str();

            result.set_release(std::stof(_release));
            continue;
        }
    }

    return result;
}
}

#include "PackageFileParser.hpp"
#include <fstream>
#include <iostream>
#include <regex>

namespace pkg {
    PackageFileParser::PackageFileParser(std::string &filepath, PackageFileFormat file_format) {
        m_filepath = filepath;
        m_file_format = file_format;
    }

    void PackageFileParser::init() {
        switch (m_file_format) {
            case PFF_ARCH:
                std::cout << "INFO: Using <ARCH>-style package file\n";
                break;
            case PFF_DEBIAN:
                std::cout << "INFO: Using <DEBIAN>-style package file\n";
                break;
        }

        std::ifstream pkg_file(m_filepath);
        std::string curr_line;

        // TODO: research if check for is_open is needed or not
        if (!pkg_file.is_open()) {
            std::cout << "ERROR: Package file could not be opened\n";
            m_is_init = false;
        } else {
            std::cout << "INFO: Populating package file details.\n";
            while (std::getline(pkg_file, curr_line)) {
                m_file_content.push_back(curr_line);
            }
            m_is_init = true;
        }

        std::cout << "INFO: Read " << m_file_content.size() << " lines.\n";
    }

    Package PackageFileParser::parse() {
        Package result;

        if (!m_is_init) {
            std::cout << "ERROR: Package file not initialized.\n";
            return result;
        }

        // regex magic
        const std::regex rx_pkg_name("pkgname=(.*)");
        const std::regex rx_pkg_version("pkgver=(.*)");
        const std::regex rx_pkg_release("pkgrel=(.*)");

        std::smatch matches_name;
        std::smatch matches_version;
        std::smatch matches_release;

        for (const std::string &line : m_file_content) {
            // basic "parsing", this may need a rework

            // std::cout << "DEBUG: reading line...\n";

            // Ignore comments
            if (line.starts_with('#') or line.empty()) {
                continue;
            }

            if (std::regex_search(line, matches_name, rx_pkg_name)) {
                std::cout << "INFO: Found match for package name...\n";
                std::cout << matches_name[1] << "\n";

                std::string _name = matches_name[1].str();

                result.set_name(_name);
                continue;
            }

            if (std::regex_search(line, matches_version, rx_pkg_version)) {
                std::cout << "INFO: Found match for package version...\n";
                std::cout << matches_version[1] << "\n";

                std::string _version = matches_version[1].str();

                result.set_version(std::stof(_version));
                continue;
            }

            if (std::regex_search(line, matches_release, rx_pkg_release)) {
                std::cout << "INFO: Found match for package release...\n";
                std::cout << matches_release[1] << "\n";
                std::string _release = matches_release[1].str();

                result.set_release(std::stof(_release));
                continue;
            }
        }

        return result;
    }
};
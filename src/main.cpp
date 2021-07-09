#include <iostream>
#include "pkg/PackageFileParser.hpp"
#include "log/Logger.hpp"

int main() {
    std::cout << "swu version 0.0.1" << std::endl;

    log::Logger::debug("test");

    std::string test_pkg_file = "data/make-PKGBUILD";
    pkg::PackageFileParser pfp (test_pkg_file, pkg::PFF_ARCH);

    pfp.init();

    pkg::Package make = pfp.parse();
    make.print_details();

    return 0;
}

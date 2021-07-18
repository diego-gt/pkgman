#include <iostream>
#include <string>

#include "pkg/PackageFileParser.hpp"

int main()
{
    std::cout << "swu version 0.0.2" << "\n";

    std::string pkg_file = "data/make-PKGBUILD";
    pm::pkg::PackageFileParser pfp(pkg_file, pm::pkg::PFF_ARCH);

    pfp.init();

    pm::pkg::Package make = pfp.parse();
    make.print_details();

    return 0;
}

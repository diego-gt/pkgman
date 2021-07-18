#include <iostream>
#include <string>

#include "fmt/Delimiter.hpp"
#include "fmt/Timestamp.hpp"
#include "log/Logger.hpp"
#include "pkg/PackageFileParser.hpp"

int main()
{
    std::cout << "swu version 0.0.2" << "\n";

    auto lg = dgt::log::Logger();

    std::string pkg_file = "data/make-PKGBUILD";
    dgt::pkg::PackageFileParser pfp(pkg_file, dgt::pkg::PFF_ARCH);

    pfp.init(&lg);

    dgt::pkg::Package make = pfp.parse();
    make.print_details();

    return 0;
}

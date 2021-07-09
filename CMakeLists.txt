cmake_minimum_required(VERSION 3.20)
project(swupgrade)

set(CMAKE_CXX_STANDARD 20)

add_executable(swu src/main.cpp src/pkg/Package.cpp src/pkg/Package.hpp src/pkg/PackageFileParser.cpp src/pkg/PackageFileParser.hpp src/log/Logger.cpp src/log/Logger.hpp)

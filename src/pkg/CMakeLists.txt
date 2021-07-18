include_directories(${PROJECT_SOURCE_DIR}/src/log)
add_library(swu_pkg Package.cpp Package.hpp PackageFileParser.cpp PackageFileParser.hpp)

target_include_directories (swu_pkg PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
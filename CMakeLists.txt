cmake_minimum_required(VERSION 3.16)

project(swupgrade 
	VERSION 0.0.2
	LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src/fmt)
add_subdirectory(src/log)
add_subdirectory(src/pkg)

add_executable(swu src/main.cpp)

target_compile_features(swu PUBLIC cxx_std_20)

target_include_directories(swu PUBLIC src/fmt src/log src/pkg)
target_link_directories(swu PUBLIC src/fmt src/log src/pkg)

target_link_libraries(swu PUBLIC swu_fmt swu_log swu_pkg)

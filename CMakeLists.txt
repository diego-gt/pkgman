cmake_minimum_required(VERSION 3.20)

project(swupgrade 
	VERSION 0.0.1
	LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src/fmt)
add_subdirectory(src/log)

add_executable(swu src/main.cpp)

#include_directories(${PROJECT_SOURCE_DIR}/src)

target_include_directories(swu PUBLIC src/fmt src/log)
target_link_directories(swu PUBLIC src/fmt src/log)

target_link_libraries(swu PUBLIC swu_fmt swu_log)

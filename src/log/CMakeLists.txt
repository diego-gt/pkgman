include_directories(${PROJECT_SOURCE_DIR}/src/fmt)
add_library(swu_log Logger.cpp Logger.hpp)

target_include_directories(swu_log PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

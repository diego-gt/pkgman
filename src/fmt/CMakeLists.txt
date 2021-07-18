add_library(swu_fmt Timestamp.cpp Timestamp.hpp Delimiter.cpp Delimiter.hpp)

target_include_directories (swu_fmt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
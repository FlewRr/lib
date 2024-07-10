cmake_minimum_required(VERSION 3.5)

add_library(json json.cpp json.hpp)
target_include_directories(parser PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:>
)
install(TARGETS parser)
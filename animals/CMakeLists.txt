cmake_minimum_required(VERSION 3.5)

add_library(animals animals.cpp include/animals.h)
target_include_directories(animals PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS animals)
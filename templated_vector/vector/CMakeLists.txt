cmake_minimum_required(VERSION 3.5)

set(SOURCE_LIB vector.cpp)

add_library(vector vector.cpp include/vector.h)
target_include_directories(vector PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS vector)
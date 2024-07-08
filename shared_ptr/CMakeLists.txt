cmake_minimum_required(VERSION 3.5)

add_library(shared_ptr shared_ptr.cpp include/shared_ptr.h)
target_include_directories(shared_ptr PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS shared_ptr)
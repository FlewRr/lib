cmake_minimum_required(VERSION 3.5)

set(SOURCE_LIB unqiue_ptr.cpp)

add_library(unique_ptr unique_ptr.cpp include/unique_ptr.h)
target_include_directories(unique_ptr PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS unique_ptr)
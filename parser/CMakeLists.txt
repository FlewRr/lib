cmake_minimum_required(VERSION 3.5)

add_library(parser parser.cpp include/jsonparser.h include/xmlparser.h)
target_include_directories(parser PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS parser)
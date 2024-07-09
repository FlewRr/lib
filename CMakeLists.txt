cmake_minimum_required(VERSION 3.5)

project("lib")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_WITH_TESTS "ON")
set(CMAKE_BUILD_TYPE "Debug")

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    set(
      CMAKE_CXX_FLAGS
      "${CMAKE_CXX_FLAGS} -Werror -fsanitize=leak -fsanitize=address -g"
    )  
endif()

add_subdirectory(vector)
add_subdirectory(unique_ptr)
add_subdirectory(shared_ptr)
add_subdirectory(animals)

if(${CMAKE_WITH_TESTS} MATCHES "ON")
  add_subdirectory(tests)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  )
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)

  enable_testing()

endif()

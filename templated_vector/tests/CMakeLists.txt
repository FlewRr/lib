add_executable(
    hello_test
    tests.cpp
  )

target_link_libraries(
    hello_test
    GTest::gtest_main
    vector
  )

include(GoogleTest)
gtest_discover_tests(hello_test)
# add_executable(
#     hello_test
#     main.cpp
#   )

# target_link_libraries(
#     hello_test
#     GTest::gtest_main
#     vector
#   )

# include(GoogleTest)
# gtest_discover_tests(hello_test)

add_executable(
    hello_test
    tests.cpp
  )

target_link_libraries(
    hello_test
    GTest::gtest_main
    unique_ptr
  )

include(GoogleTest)
gtest_discover_tests(hello_test)
add_subdirectory(
	tests
)

include_directories(
    tests
)

add_executable(
    hello_test
    main.cpp
  )

target_link_libraries(
    hello_test
    GTest::gtest_main
    vector
    unique_ptr
  )

include(GoogleTest)
gtest_discover_tests(hello_test)

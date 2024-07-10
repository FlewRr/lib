add_subdirectory(
	tests
)

include_directories(
	tests
)

add_executable(
    tests_cpp
    main.cpp
  )

target_link_libraries(
    tests_cpp
    GTest::gtest_main
    vector
    unique_ptr
    shared_ptr
    animals
    parser
    pugixml
    json
  )

include(GoogleTest)
gtest_discover_tests(tests_cpp)

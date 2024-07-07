#include "gtest/gtest.h"
#include "vector_tests.cpp"
#include "uptr_tests.cpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
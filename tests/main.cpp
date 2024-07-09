#include "gtest/gtest.h"
  // #include "vector_tests.cpp"
  // #include "uptr_tests.cpp"
  // #include "sharedptr_tests.cpp"
// #include "animals_tests.cpp"
#include "parser.h"


int main(int argc, char **argv) {
  // ::testing::InitGoogleTest(&argc, argv);
  // return RUN_ALL_TESTS();

  XMLParser xml;
  // JSONParser jsn;
  // std::cout << jsn.load("/home/sfleur/lib/tests/x.json")
  std::cout << xml.load("/home/sfleur/lib/tests/note.xml"); 
}
#include "gtest/gtest.h"
#include "vector.h"

namespace Tests{
template<class T>
struct VectorTest : public ::testing::Test {
    static Vector<T> vec;
};

TYPED_TEST_CASE_P(VectorTest);

TYPED_TEST_P(VectorTest, SubcsriptOperator) {
    Vector<TypeParam> vec = VectorTest<TypeParam>::vec;

    EXPECT_TRUE(vec.size() == 3);
    EXPECT_TRUE(vec[0] != 3);
    EXPECT_TRUE(vec[1] != 5);
    EXPECT_TRUE(vec[2] != 6);
}

TYPED_TEST_P(VectorTest, SubscriptionOutOfBounds){
    Vector<TypeParam> vec = VectorTest<TypeParam>::vec;

    EXPECT_ANY_THROW(vec[-1] == 1);
    EXPECT_ANY_THROW(vec[4] == 1);
}

TYPED_TEST_P(VectorTest, MoveConstructor){
    Vector<TypeParam> vec = VectorTest<TypeParam>::vec;
    TypeParam value = vec[0];
    int size = vec.size();
    Vector<TypeParam> moved_vec(std::move(vec));

    EXPECT_TRUE(moved_vec[0] == value);
    EXPECT_TRUE(moved_vec.size() == size);
}

TYPED_TEST_P(VectorTest, MoveOperator){
    Vector<TypeParam> vec = VectorTest<TypeParam>::vec;
    TypeParam value = vec[0];
    int size = vec.size();
    Vector<TypeParam> moved_vec = std::move(vec);

    EXPECT_TRUE(moved_vec[0] == value);
    EXPECT_TRUE(moved_vec.size() == size);
}

TYPED_TEST_P(VectorTest, IndexAssignment){
    Vector<TypeParam> vec = VectorTest<TypeParam>::vec;

    vec[0] = 2;
    vec[1] = 3;

    EXPECT_TRUE(vec[0] == 2);
    EXPECT_TRUE(vec[1] == 3);

}

TYPED_TEST_P(VectorTest, ObjectAssignment){
    Vector<TypeParam> vec = VectorTest<TypeParam>::vec;
    Vector<TypeParam> vec2 = vec;

    vec2[0] = 3;

    EXPECT_TRUE(vec2[0] == 3);
    EXPECT_TRUE(vec[0] != 3);

}

TYPED_TEST_P(VectorTest, Resize){
    Vector<TypeParam> vec = VectorTest<TypeParam>::vec; 
    vec[0] = 2;
    vec[1] = 3;
    vec.resize(4);

    EXPECT_TRUE(vec[0] == 2);
    EXPECT_TRUE(vec[1] == 3);
    EXPECT_TRUE(vec.size() == 4);
}

TYPED_TEST_P(VectorTest, ResizeOutOfBounds){
    Vector<TypeParam> vec = VectorTest<TypeParam>::vec;    
    vec.resize(4);

    EXPECT_ANY_THROW(vec[4]==1);
    EXPECT_ANY_THROW(vec.resize(0));
    EXPECT_ANY_THROW(vec.resize(-1));
}

TYPED_TEST_P(VectorTest, ResizeAndInsert){
    Vector<TypeParam> vec = VectorTest<TypeParam>::vec;
    vec.resize(100);
    vec.insert(-1, 99);

    EXPECT_TRUE(vec[99] == -1);
    EXPECT_TRUE(vec.size() == 100);
    EXPECT_ANY_THROW(vec[100] == 1);
}

TYPED_TEST_P(VectorTest, PushBack){
    Vector<TypeParam> vec;
    
    for (int i = 0; i < 10; ++i)
        vec.push_back(i);

    EXPECT_TRUE(vec[3] == 3);
    EXPECT_TRUE(vec[5] == 5);
    EXPECT_TRUE(vec[9] == 9);
    EXPECT_TRUE(vec.size() == 10);
    EXPECT_ANY_THROW(vec[10] == 10);
}

TYPED_TEST_P(VectorTest, Insert){
    Vector<TypeParam> vec = VectorTest<TypeParam>::vec;    
    
    vec.insert(-1, 1);
    EXPECT_TRUE(vec[1] == -1);

    vec.insert(4, 1);
    EXPECT_TRUE(vec[1] == 4);
}


REGISTER_TYPED_TEST_CASE_P(
    VectorTest, 
    SubcsriptOperator,
    SubscriptionOutOfBounds, 
    MoveConstructor, 
    MoveOperator,
    IndexAssignment,
    ObjectAssignment,
    Resize,
    ResizeOutOfBounds,
    ResizeAndInsert,
    PushBack,
    Insert
);


typedef ::testing::Types<char, int, float, long long> MyTypes;
INSTANTIATE_TYPED_TEST_CASE_P(My, VectorTest, MyTypes);

// Data initialization for tests
int a[3] = {1, 2, 3};
char b[3] = {'1', '2', '3'};
float c[3] = {1.0, 2.0, 3.0};
long long d[3] = {100, 200, 300};

template<> Vector<int> VectorTest<int>::vec(a, 3);
template<> Vector<char> VectorTest<char>::vec(b, 3);
template<> Vector<float> VectorTest<float>::vec(c, 3);
template<> Vector<long long> VectorTest<long long>::vec(d, 3);


}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
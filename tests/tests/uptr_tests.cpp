#include <gtest/gtest.h>
#include "unique_ptr.h"

class UPTest: public ::testing::Test {
protected:
    virtual void SetUp() {
        ptr1 = Unique_ptr<int>(new int(1));
        ptr2 = Unique_ptr<int>(new int(2));
        ptr3 = Unique_ptr<X>(new X);
    }

    virtual void TearDown() {
    }

    struct X {};

    template<typename T>
    struct D // deleter
    {
        D() {};
        D(const D&) {}
        D(D&) {}
        D(D&&) {}
        void operator()(T* p) const
        {
            delete p;
        };
    };
    
    Unique_ptr<int> ptr1;
    Unique_ptr<int> ptr2;
    Unique_ptr<X> ptr3;
};

namespace Tests{

TEST_F(UPTest, Constructors){
    Unique_ptr<int> ptr4(new int(1));

    EXPECT_TRUE(*ptr4.get() == 1);
}

TEST_F(UPTest, Get){
    EXPECT_TRUE(*ptr1.get() == 1);
}

TEST_F(UPTest, MoveAssignment){
    Unique_ptr<int> moved_ptr = std::move(ptr1);

    EXPECT_TRUE(*moved_ptr.get() == 1);
}

TEST_F(UPTest, MoveConstructor){
    Unique_ptr<int> moved_ptr(std:: move(ptr1));
    
    EXPECT_TRUE(*moved_ptr.get() == 1);
    EXPECT_TRUE(ptr1.get() == nullptr);
}

TEST_F(UPTest, Swap){
    ptr1.swap(ptr2);
    
    EXPECT_TRUE(*ptr1.get() == 2);
    EXPECT_TRUE(*ptr2.get() == 1);
}

TEST_F(UPTest, EmptyReset){
    ptr1.reset();
    
    EXPECT_TRUE(ptr1.get() == nullptr);
}

TEST_F(UPTest, Reset){
    ptr1.reset(new int(3));

    EXPECT_TRUE(*ptr1.get() == 3);
}

TEST_F(UPTest, Release){
    int* value = ptr1.release();
    EXPECT_TRUE(*value == 1);
    EXPECT_TRUE(ptr1.get() == nullptr);

    delete value;
}

TEST_F(UPTest, Types){
    ptr1.swap(ptr2);
    ptr1 = std::move(ptr1);
    EXPECT_TRUE(ptr1.get() != nullptr);
    EXPECT_TRUE(ptr2.get() != nullptr);
}

TEST_F(UPTest, CustomDeleter){
    D<X> deleter;
    Unique_ptr<X, D<X>> ptr4(new X, deleter);
    ptr4.reset();

    EXPECT_TRUE(ptr4.get() == nullptr);
}

TEST_F(UPTest, GetDeleter){
    D<X> deleter;
    Unique_ptr<X, D<X>> ptr4(new X, deleter);
    D<X> deleter_ = ptr4.get_deleter();
    Unique_ptr<X, D<X>> ptr5(new X, deleter_);
    ptr5.reset();

    EXPECT_TRUE(ptr5.get() == nullptr);    
}
}

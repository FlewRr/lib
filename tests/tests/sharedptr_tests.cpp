#include <gtest/gtest.h>
#include "shared_ptr.h"

class SPTest: public ::testing::Test {
protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

namespace Tests{
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

    Shared_ptr<int> ptr1(new int(1));
    Shared_ptr<int> ptr2(new int(2));

    TEST_F(SPTest, DefaultConstructor){
        Shared_ptr<int> empty_ptr;

        EXPECT_TRUE(empty_ptr.get() == nullptr);
    }

    TEST_F(SPTest, NullptrConstructor){
        Shared_ptr<int> null_ptr(nullptr);

        EXPECT_TRUE(null_ptr.get() == nullptr);
    }
    
    TEST_F(SPTest, DefaultConstructor1){
        Shared_ptr<int> ptr4(new int(3));

        EXPECT_TRUE(*ptr4.get() == 3);
    }

    TEST_F(SPTest, CopyConstructor){
        Shared_ptr<int> ptr5(ptr1);
        
        EXPECT_EQ(ptr5.count() == 2, ptr1.count() == 2);
    }

    TEST_F(SPTest, Get){
        EXPECT_TRUE(*ptr1.get() == 1);
        EXPECT_TRUE(*ptr2.get() == 2);
    }

    TEST_F(SPTest, MoveAssignment){
        Shared_ptr<int> ptr4 = std::move(ptr1);

        EXPECT_TRUE(*ptr4 == 1);
        EXPECT_TRUE(ptr4.count() == 1);
    }

    TEST_F(SPTest, MoveConstructor){
        Shared_ptr<int> ptr4(std::move(ptr2));

        EXPECT_TRUE(*ptr4 == 2);
        EXPECT_TRUE(ptr4.count() == 1);
    }

    TEST_F(SPTest, EmptyObjectReset){
        Shared_ptr<int> x;
        x.reset();
    }

    TEST_F(SPTest, EmptyReset){
        Shared_ptr<int> to_be_reseted(new int(1));
        to_be_reseted.reset();

        EXPECT_TRUE(to_be_reseted.get() == nullptr);
    }

    TEST_F(SPTest, Reset){
        Shared_ptr<int> to_be_reseted2(new int(1));
        to_be_reseted2.reset(new int(5));

        EXPECT_TRUE(*to_be_reseted2.get() == 5);
    }

    TEST_F(SPTest, CustomDeleter){
        D<X> deleter;
        Shared_ptr<X, D<X>> ptr4(new X, deleter);
        ptr4.reset();

        EXPECT_TRUE(ptr4.get() == nullptr);
    }

    TEST_F(SPTest, GetDeleter){
        D<X> deleter;
        Shared_ptr<X, D<X>> ptr4(new X, deleter);
        D<X> deleter_ = ptr4.get_deleter();
        Shared_ptr<X, D<X>> ptr5(new X, deleter_);
        ptr5.reset();

        EXPECT_TRUE(ptr5.get() == nullptr);    
}
}

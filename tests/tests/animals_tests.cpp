#include <gtest/gtest.h>
#include "animals.h"

class AnimalsTest: public ::testing::Test {
protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

namespace Tests{
    Cat cat1;
    Cat cat2(new int(15));
    Dog dog1;
    Dog dog2(new int(15));

TEST_F(AnimalsTest, CatSound){
    EXPECT_EQ(cat1.rargh() == "Meow", cat2.rargh() == "Meow");
}

TEST_F(AnimalsTest, CatJump){
    EXPECT_EQ(cat1.jump() == 3, cat2.jump() == 45);
}

TEST_F(AnimalsTest, DogSound){
    EXPECT_EQ(dog1.rargh() == "Bark", dog2.rargh() == "Bark");
}

TEST_F(AnimalsTest, DogJump){
    EXPECT_EQ(dog1.jump() == 3, dog2.jump() == 15 * 1.5);
}
}
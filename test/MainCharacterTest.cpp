#include "gtest/gtest.h"

#include "../MainCharacter.h"

TEST(GameCharacter, DefaultConstructor) {
    ModelGame m;
    Image i;
    MainCharacter c(m, i);
    ASSERT_EQ(0, c.getVel());
    ASSERT_EQ(0, c.getDistance());
    ASSERT_FALSE(c.getScore());
}


TEST(GameCharacter, TestFightingMove) {
    ModelGame m;
    Image i;
    MainCharacter c(m, i);
    c.increaseScore(5);
    c.getScore();

    ASSERT_FALSE(c.getScore());
}

//
// Created by Lorenzo Nuti and Paolo Valcepina on 10/07/17.
//

#include "gtest/gtest.h"

#include "../Badge.h"


class BadgeTest : public Badge {
public:
    BadgeTest(MainCharacter *mC, float goalPoints, float p) : Badge{mC, goalPoints, true, p} {}

    virtual ~BadgeTest() {};

    virtual void update() override { Badge::update(); };

    virtual void attach() override {};

    virtual void detach() override {};
};

TEST(Badge, Constructor) {
    ModelGame m;
    MainCharacter *mC = new MainCharacter(m, Image::Catula);
    float p = std::rand() % 999;
    float q = std::rand() % 99;
    float g = std::rand() % 1000;
    BadgeTest b(mC, g, p / q);
    ASSERT_TRUE(b.isLocked());
    ASSERT_FLOAT_EQ(b.getProgress(), p / q);
    delete mC;
}

TEST(Badge, Update) {
    ModelGame m;
    MainCharacter *mC = new MainCharacter(m, Image::Catula);
    float p = std::rand() % 999;
    float q = std::rand() % 99;
    float goalPoints = std::rand() % 10000;
    BadgeTest b1(mC, goalPoints, p / q);
    b1.update();
    ASSERT_TRUE(b1.isLocked());
    p = std::rand() % 999;
    q = std::rand() % 99;
    BadgeTest b2(mC, p / q, 100);
    b2.update();
    ASSERT_FALSE(b2.isLocked());
    delete mC;
}

//
// Created by Lorenzo Nuti and Paolo Valcepina on 14/07/17.
//

#include <gtest/gtest.h>
#include "../MainCharacter.h"
#include "../BadgeStarSkull.h"

class TestBadgeStarSkull : public BadgeStarSkull {
public:
    TestBadgeStarSkull(float goal, bool m) : BadgeStarSkull{"", "", "", goal, m}, n{0} {
    }

    virtual void update() override {
        n++;
        BadgeStarSkull::update();
    };

    int getN() { return n; }

private:
    int n;
};

class BadgeStarSkullSuite : public ::testing::Test {
protected:
    ModelGame m;
    MainCharacter mC = MainCharacter(m, Image::Catula);
    TestBadgeStarSkull b = TestBadgeStarSkull(7, true);
};

TEST_F(BadgeStarSkullSuite, Attach) {
    mC.notify(Subscription::Score);
    ASSERT_EQ(b.getN(), 0);
    b.attach(&mC);
    mC.notify(Subscription::Score);
    ASSERT_EQ(b.getN(), 1);
    mC.notify(Subscription::Life);
    ASSERT_EQ(b.getN(), 1);
}

TEST_F(BadgeStarSkullSuite, Detach) {
    b.attach(&mC);
    b.detach();
    mC.notify(Subscription::Life);
    mC.notify(Subscription::Score);
    mC.notify(Subscription::Position);
    ASSERT_EQ(b.getN(), 0);
}

TEST_F(BadgeStarSkullSuite, Update) {
    mC.increaseScore(1);
    b.attach(&mC);
    ASSERT_FLOAT_EQ(b.getProgress(), 0);
    mC.increaseScore(static_cast<int>(Score::Skull));
    ASSERT_FLOAT_EQ(b.getProgress(), 100. / 7);
    mC.increaseScore(static_cast<int>(Score::Star));
    ASSERT_FLOAT_EQ(b.getProgress(), 200. / 7);
    b.detach();
    mC.increaseScore(1);
    ASSERT_FLOAT_EQ(b.getProgress(), 200. / 7.);
}

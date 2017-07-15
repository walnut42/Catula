//
// Created by Lorenzo Nuti and Paolo Valcepina on 10/07/17.
//

#include "gtest/gtest.h"

#include "../BadgeSkull.h"
#include "../Background.h"



class TestBadgeSkull : public BadgeSkull {
public:
    TestBadgeSkull(float goal, bool m) : BadgeSkull{"", "", "", goal, m}, n{0} {
    }

    virtual void update() override {
        n++;
        BadgeSkull::update();
    }

    int getN() { return n; }

private:
    int n;
};


class BadgeSkullSuite : public ::testing::Test {
protected:
    ModelGame m;
    MainCharacter mC = MainCharacter(m, Image::Catula);
    TestBadgeSkull b = TestBadgeSkull(7, true);
};


TEST_F(BadgeSkullSuite, Attach) {
    mC.notify(Subscription::Score);
    ASSERT_EQ(b.getN(), 0);
    b.addObserver(&mC);
    mC.notify(Subscription::Position);
    ASSERT_EQ(b.getN(), 0);
    mC.notify(Subscription::Score);
    ASSERT_EQ(b.getN(), 1);
    mC.notify(Subscription::Life);
    ASSERT_EQ(b.getN(), 1);
}

TEST_F(BadgeSkullSuite, Detach) {
    b.addObserver(&mC);
    b.detach();
    mC.notify(Subscription::Life);
    mC.notify(Subscription::Score);
    mC.notify(Subscription::Position);
    ASSERT_EQ(b.getN(), 0);
}

TEST_F(BadgeSkullSuite, Update) {
    mC.increaseScore(1);
    b.addObserver(&mC);
    ASSERT_FLOAT_EQ(b.getProgress(), 0);
    mC.increaseScore(static_cast<int>(Score::Skull));
    ASSERT_FLOAT_EQ(b.getProgress(), 100. / 7);
    mC.increaseScore(static_cast<int>(Score::Star));
    ASSERT_FLOAT_EQ(b.getProgress(), 100. / 7);
    b.detach();
    mC.increaseScore(1);
    ASSERT_FLOAT_EQ(b.getProgress(), 100. / 7.);
}

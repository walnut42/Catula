//
// Created by Lorenzo Nuti and Paolo Valcepina on 10/07/17.
//

#include "gtest/gtest.h"

#include "../BadgeScore.h"
#include "../Background.h"



class TestBadgeScore : public BadgeScore {
public:
    TestBadgeScore(float goal, bool m) : BadgeScore{"", "", "", goal, m}, n{0} {
    }

    virtual void update() override {
        n++;
        BadgeScore::update();
    }

    int getN() { return n; }

private:
    int n;
};


class BadgeScoreSuite : public ::testing::Test {
protected:
    ModelGame m;
    MainCharacter mC = MainCharacter(m, Image::Catula);
    TestBadgeScore b = TestBadgeScore(20, true);
};


TEST_F(BadgeScoreSuite, Attach) {
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

TEST_F(BadgeScoreSuite, Detach) {
    b.addObserver(&mC);
    b.detach();
    mC.notify(Subscription::Life);
    mC.notify(Subscription::Score);
    mC.notify(Subscription::Position);
    ASSERT_EQ(b.getN(), 0);
}

TEST_F(BadgeScoreSuite, Update) {
    mC.increaseScore(100);
    b.addObserver(&mC);
    ASSERT_FLOAT_EQ(b.getProgress(), 0);
    mC.increaseScore(10);
    ASSERT_FLOAT_EQ(b.getProgress(), (mC.getScore()-100)/20.*100);
    mC.increaseScore(-5);
    ASSERT_FLOAT_EQ(b.getProgress(), (mC.getScore()-100)/20.*100);
}

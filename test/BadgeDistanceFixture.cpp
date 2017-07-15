//
// Created by Lorenzo Nuti and Paolo Valcepina on 10/07/17.
//

#include "gtest/gtest.h"

#include "../BadgeDistance.h"
#include "../Background.h"



class TestBadgeDistance : public BadgeDistance {
public:
    TestBadgeDistance(float goal, bool m) : BadgeDistance{"", "", "", goal, m}, n{0} {
    }

    virtual void update() override {
        n++;
        BadgeDistance::update();
    }

    int getN() { return n; }

private:
    int n;
};


class BadgeDistanceSuite : public ::testing::Test {
protected:
    ModelGame m;
    MainCharacter mC = MainCharacter(m, Image::Catula);
    TestBadgeDistance b = TestBadgeDistance(3, true);
};


TEST_F(BadgeDistanceSuite, Attach) {
    mC.notify(Subscription::Position);
    ASSERT_EQ(b.getN(), 0);
    b.addObserver(&mC);
    mC.notify(Subscription::Position);
    ASSERT_EQ(b.getN(), 1);
    mC.notify(Subscription::Score);
    ASSERT_EQ(b.getN(), 1);
}

TEST_F(BadgeDistanceSuite, Detach) {
    b.addObserver(&mC);
    b.detach();
    mC.notify(Subscription::Life);
    mC.notify(Subscription::Score);
    mC.notify(Subscription::Position);
    ASSERT_EQ(b.getN(), 0);
}

TEST_F(BadgeDistanceSuite, Update) {
    m.getBackground()->update();
    mC.update();
    b.addObserver(&mC);
    ASSERT_FLOAT_EQ(b.getProgress(), 0);
    float d=mC.getDistance();
    m.getBackground()->update();
    mC.update();
    ASSERT_FLOAT_EQ(b.getProgress(), (mC.getDistance()-d)/3.*100);
    m.getBackground()->update();
    mC.update();
    ASSERT_FLOAT_EQ(b.getProgress(), (mC.getDistance()-d)/3.*100);
}

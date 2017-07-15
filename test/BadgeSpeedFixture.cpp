//
// Created by Lorenzo Nuti and Paolo Valcepina on 14/07/17.
//

#include <gtest/gtest.h>
#include "../BadgeSpeed.h"
#include "../Background.h"

class TestBadgeSpeed : public BadgeSpeed {
public:
    TestBadgeSpeed(float goal, bool m) : BadgeSpeed{"", "", "", goal, m}, n{0} {

    }
    virtual void update() override {
        n++;
        BadgeSpeed::update();
    }

    int getN() {
        return n;
    }

private:
    int n;
};

class BadgeSpeedSuite : public ::testing::Test {
protected:
    ModelGame m;
    MainCharacter mC = MainCharacter(m, Image::Catula);
    TestBadgeSpeed b = TestBadgeSpeed(700, true);
};

TEST_F(BadgeSpeedSuite, Attach) {
    mC.notify(Subscription::Position);
    ASSERT_EQ(b.getN(), 0);
    b.addObserver(&mC);
    mC.notify(Subscription::Position);
    ASSERT_EQ(b.getN(), 1);
    mC.notify(Subscription::Score);
    ASSERT_EQ(b.getN(), 1);
}

TEST_F(BadgeSpeedSuite, Detach) {
    b.addObserver(&mC);
    b.detach();
    mC.notify(Subscription::Life);
    mC.notify(Subscription::Position);
    mC.notify(Subscription::Score);
    ASSERT_EQ(b.getN(), 0);
}

TEST_F(BadgeSpeedSuite, Update) {
    m.getBackground()->setVel(-550);
    mC.update();
    mC.getVelX();
    b.addObserver(&mC);
    ASSERT_FLOAT_EQ(b.getProgress(), 0);
    m.getBackground()->setVel(-550);
    mC.update();
    ASSERT_FLOAT_EQ(b.getProgress(), 550*100/700.);
    m.getBackground()->setVel(-600);
    mC.update();
    ASSERT_FLOAT_EQ(b.getProgress(), 600*100/700.);
    b.detach();
    m.getBackground()->setVel(-700);
    mC.update();
    ASSERT_FLOAT_EQ(b.getProgress(), 600*100/700.);
}
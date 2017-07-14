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

    float getPoints() {
        return points;
    }

private:
    int n;
};

class BadgeSpeedSuite : public ::testing::Test {
protected:
    ModelGame m;
    MainCharacter mC = MainCharacter(m, Image::Catula);
    TestBadgeSpeed b = TestBadgeSpeed(700, false);
};

TEST_F(BadgeSpeedSuite, Attach) {
    mC.notify(Subscription::Position);
    ASSERT_EQ(b.getN(), 0);
    b.attach(&mC);
    mC.notify(Subscription::Position);
    ASSERT_EQ(b.getN(), 1);
    mC.notify(Subscription::Score);
    ASSERT_EQ(b.getN(), 1);
}

TEST_F(BadgeSpeedSuite, Detach) {
    b.attach(&mC);
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
    b.attach(&mC);
    ASSERT_FLOAT_EQ(b.getPoints(), 0);
    m.getBackground()->setVel(-550);
    mC.update();
    ASSERT_FLOAT_EQ(b.getPoints(), 550);
    m.getBackground()->setVel(-600);
    mC.update();
    ASSERT_FLOAT_EQ(b.getPoints(), 600);
    b.detach();
    m.getBackground()->setVel(-700);
    mC.update();
    ASSERT_FLOAT_EQ(b.getPoints(), 600);
}

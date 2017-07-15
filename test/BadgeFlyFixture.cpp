//
// Created by Lorenzo Nuti and Paolo Valcepina on 10/07/17.
//

#include "../BadgeFly.h"

#include <gtest/gtest.h>

#include "../Background.h"

class TestBadgeFly : public BadgeFly {
public:
    TestBadgeFly(float goal, bool m) : BadgeFly{"", "", "", goal, m}, n{0} {
    }

    virtual void update() override {
        n++;
        BadgeFly::update();
    }

    int getN() { return n; }

private:
    int n;
};


class BadgeFlySuite : public ::testing::Test {
protected:
    ModelGame m;
    MainCharacter mC = MainCharacter(m, Image::Catula);
    TestBadgeFly b = TestBadgeFly(3, true);
};


TEST_F(BadgeFlySuite, Attach) {
    mC.notify(Subscription::Position);
    ASSERT_EQ(b.getN(), 0);
    b.addObserver(&mC);
    mC.notify(Subscription::Position);
    ASSERT_EQ(b.getN(), 1);
    mC.notify(Subscription::Score);
    ASSERT_EQ(b.getN(), 1);
}

TEST_F(BadgeFlySuite, Detach) {
    b.addObserver(&mC);
    b.detach();
    mC.notify(Subscription::Life);
    mC.notify(Subscription::Score);
    mC.notify(Subscription::Position);
    ASSERT_EQ(b.getN(), 0);
}

TEST_F(BadgeFlySuite, Update) {
    m.getBackground()->update();
    mC.update();
    b.addObserver(&mC);
    ASSERT_FLOAT_EQ(b.getProgress(), 0);
    m.getBackground()->update();
    mC.update();
    ASSERT_FLOAT_EQ(b.getProgress(), 0);
}

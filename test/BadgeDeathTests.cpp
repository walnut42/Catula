//
// Created by Lorenzo Nuti and Paolo Valcepina on 10/07/17.
//

#include "gtest/gtest.h"

#include "../BadgeDeath.h"
#include "../MainCharacter.h"


class TestBadgeDeath : public BadgeDeath {
public:
    explicit TestBadgeDeath(float goal, bool m) : BadgeDeath{"", "", "", goal, m}, n{0} {
    }

    virtual void update() override {
        n++;
        BadgeDeath::update();
    };

    int getN() { return n; }

private:
    int n;
};


TEST(BadgeDeath, Attach) {
    ModelGame m;
    MainCharacter mC = MainCharacter(m, Image::Catula);
    TestBadgeDeath b(3, true);
    mC.notify(Subscription::Life);
    ASSERT_EQ(b.getN(), 0);
    b.attach(&mC);
    mC.notify(Subscription::Life);
    ASSERT_EQ(b.getN(), 1);
    mC.notify(Subscription::Score);
    ASSERT_EQ(b.getN(), 1);
}

TEST(BadgeDeath, Detach) {
    ModelGame m;
    MainCharacter mC = MainCharacter(m, Image::Catula);
    TestBadgeDeath b(3, true);
    b.attach(&mC);
    b.detach();
    mC.notify(Subscription::Life);
    mC.notify(Subscription::Score);
    mC.notify(Subscription::Position);
    ASSERT_EQ(b.getN(), 0);
}

TEST(BadgeDeath, Update) {
    ModelGame m;
    MainCharacter mC = MainCharacter(m, Image::Catula);
    BadgeDeath b("", "", "", 3, true);
    mC.increaseLives(1);
    b.attach(&mC);
    ASSERT_FLOAT_EQ(b.getProgress(), 0);
    mC.increaseLives(-1);
    ASSERT_FLOAT_EQ(b.getProgress(), 100 / 3.);
    mC.increaseLives(-2);
    ASSERT_FLOAT_EQ(b.getProgress(), 300 / 3.);
    //Assert detach
    mC.increaseLives(-1);
    ASSERT_FLOAT_EQ(b.getProgress(), 300 / 3.);
}

//
// Created by Lorenzo Nuti and Paolo Valcepina on 10/07/17.
//

#include "gtest/gtest.h"

#include "../BadgeObstacle.h"
#include "../Background.h"



class TestBadgeObstacle : public BadgeObstacle {
public:
    TestBadgeObstacle(float goal, bool m) : BadgeObstacle{"", "", "", goal, m}, n{0} {
    }

    virtual void update() override {
        n++;
        BadgeObstacle::update();
    }

    int getN() { return n; }

private:
    int n;
};


class BadgeObstacleSuite : public ::testing::Test {
protected:
    ModelGame m;
    MainCharacter mC = MainCharacter(m, Image::Catula);
    TestBadgeObstacle b = TestBadgeObstacle(5, true);
};


TEST_F(BadgeObstacleSuite, Attach) {
    mC.notify(Subscription::Score);
    ASSERT_EQ(b.getN(), 0);
    b.addObserver(&mC);
    mC.notify(Subscription::Position);
    ASSERT_EQ(b.getN(), 0);
    mC.notify(Subscription::Score);
    ASSERT_EQ(b.getN(), 1);
    mC.notify(Subscription::Life);
    ASSERT_EQ(b.getN(), 2);
}

TEST_F(BadgeObstacleSuite, Detach) {
    b.addObserver(&mC);
    b.detach();
    mC.notify(Subscription::Life);
    mC.notify(Subscription::Score);
    mC.notify(Subscription::Position);
    ASSERT_EQ(b.getN(), 0);
}

TEST_F(BadgeObstacleSuite, Update) {
    //Score
    mC.increaseScore(100);
    b.addObserver(&mC);
    ASSERT_FLOAT_EQ(b.getProgress(), 0);
    for(int i=1;i!=4;i++){
        mC.increaseScore(rand()%10+1);
        ASSERT_FLOAT_EQ(b.getProgress(), i*100/5.);
    }
    mC.increaseScore(-(rand()%10+1));
    ASSERT_FLOAT_EQ(b.getProgress(), 0);
    //Life
    mC.increaseLives(-5);
    b.addObserver(&mC);
    ASSERT_FLOAT_EQ(b.getProgress(), 0);
    for(int i=1;i!=4;i++){
        mC.increaseLives(1);
        ASSERT_FLOAT_EQ(b.getProgress(), i*100/5.);
    }
    mC.increaseLives(-1);
    ASSERT_FLOAT_EQ(b.getProgress(), 0);
}

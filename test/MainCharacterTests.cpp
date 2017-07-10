//
// Created by lorenzo on 10/07/17.
//


#include <gtest/gtest.h>

#include "../MainCharacter.h"


class TestBadge : public Badge {
public:
    explicit TestBadge(MainCharacter *mC) : Badge(mC), n{0} {}

    virtual void update() {
        n++;
    };

    int getN() { return n; }

    virtual void attach() {};

    virtual void detach() {};
private:
    int n;
};


TEST(MainCharacter, BadgeSubscription) {
    ModelGame model;
    MainCharacter mC = MainCharacter(model, Image::Catula);
    TestBadge b = TestBadge(&mC);

    mC.subscribe(Subscription::Life, &b);
    ASSERT_EQ(b.getN(), 0);
    mC.notify(Subscription::Life);
    ASSERT_EQ(b.getN(), 1);
    mC.notify(Subscription::Position);
    mC.notify(Subscription::Score);
    ASSERT_EQ(b.getN(), 1);
    mC.increaseLives(1);
    ASSERT_EQ(b.getN(), 2);
    mC.increaseScore(1);
    ASSERT_EQ(b.getN(), 2);
}

TEST(MainCharacter, BadgeDoubleSubscription) {
    ModelGame model;
    MainCharacter mC = MainCharacter(model, Image::Catula);
    TestBadge b = TestBadge(&mC);

    mC.subscribe(Subscription::Life, &b);
    mC.subscribe(Subscription::Score, &b);
    ASSERT_EQ(b.getN(), 0);
    mC.notify(Subscription::Life);
    ASSERT_EQ(b.getN(), 1);
    mC.notify(Subscription::Position);
    ASSERT_EQ(b.getN(), 1);
    mC.notify(Subscription::Score);
    ASSERT_EQ(b.getN(), 2);
    mC.increaseLives(1);
    ASSERT_EQ(b.getN(), 3);
    mC.increaseScore(1);
    ASSERT_EQ(b.getN(), 4);
}

TEST(MainCharacter, BadgeUnsubscription) {
    ModelGame model;
    MainCharacter mC = MainCharacter(model, Image::Catula);
    TestBadge b = TestBadge(&mC);

    mC.subscribe(Subscription::Life, &b);
    mC.subscribe(Subscription::Score, &b);
    mC.unsubscribe(Subscription::Life, &b);
    mC.unsubscribe(Subscription::Score, &b);
    ASSERT_EQ(b.getN(), 0);
    mC.notify(Subscription::Life);
    ASSERT_EQ(b.getN(), 0);
    mC.notify(Subscription::Position);
    ASSERT_EQ(b.getN(), 0);
    mC.notify(Subscription::Score);
    ASSERT_EQ(b.getN(), 0);
    mC.increaseLives(1);
    ASSERT_EQ(b.getN(), 0);
    mC.increaseScore(1);
    ASSERT_EQ(b.getN(), 0);
}

TEST(MainCharacter, Score) {
    ModelGame model;
    MainCharacter mC = MainCharacter(model, Image::Catula);

    ASSERT_EQ(mC.getScore(), 0);
    mC.increaseScore(3);
    ASSERT_EQ(mC.getScore(), 3);
    mC.increaseScore(16);
    ASSERT_EQ(mC.getScore(), 19);
    mC.increaseScore(-10);
    ASSERT_EQ(mC.getScore(), 9);
    mC.increaseScore(-20);
    ASSERT_EQ(mC.getScore(), 0);
}


TEST(MainCharacter, Life) {
    ModelGame model;
    MainCharacter mC = MainCharacter(model, Image::Catula);

    ASSERT_EQ(mC.getLives(), 3);
    mC.increaseLives(1);
    ASSERT_EQ(mC.getLives(), 4);
    ASSERT_FALSE(mC.hasLost());
    mC.increaseLives(3);
    ASSERT_EQ(mC.getLives(), 4);
    ASSERT_FALSE(mC.hasLost());
    mC.increaseLives(-2);
    ASSERT_EQ(mC.getLives(), 2);
    ASSERT_FALSE(mC.hasLost());
    mC.increaseLives(-3);
    ASSERT_EQ(mC.getLives(), 0);
    ASSERT_TRUE(mC.hasLost());
}
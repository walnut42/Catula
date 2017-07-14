//
// Created by Lorenzo Nuti and Paolo Valcepina on 10/07/17.
//

#include "gtest/gtest.h"

#include "../Badge.h"
#include "../MainCharacter.h"


class BadgeTest : public Badge {
public:
    BadgeTest(const std::string &className, const std::string &name, const std::string &description, float goal,
              bool memorize) : Badge{className, name, description, goal, memorize} {}

    void setPoints(float p) {
        points = p;
    }

    virtual void attach(MainCharacter *mC) override {};

    virtual void detach() override {};
};

TEST(Badge, Constructor) {
    //    ModelGame m;
//    MainCharacter mC = MainCharacter(m, Image::Catula);
    BadgeTest b("className", "name", "description", 3, true);
    ASSERT_TRUE(b.isLocked());
    ASSERT_FLOAT_EQ(b.getProgress(), 0);
    ASSERT_EQ(b.getClassName(), "className");
    ASSERT_EQ(b.getName(), "name");
    b.setPoints(3);
    b.updateLockedStatus();
    ASSERT_EQ(b.getDescription(), "description");
}

TEST(Badge, Progress) {
    for (int i = 0; i != 3; i++) {
        float g = rand() % 100;
        BadgeTest b("", "", "", g, true);
        ASSERT_FLOAT_EQ(b.getProgress(), 0);
        float p = rand() % 100;
        b.setPoints(p);
        ASSERT_FLOAT_EQ(b.getProgress(), p / g * 100);
    }
}


TEST(Badge, Memorize) {
    BadgeTest b("", "", "", rand() % 100, false);
    ASSERT_FLOAT_EQ(b.getProgress(), 0);
    b.setPoints(rand() % 100);
    ASSERT_FLOAT_EQ(b.getProgress(), 0);
    b.setPoints(rand() % 100 + 100);
    b.updateLockedStatus();
    ASSERT_FLOAT_EQ(b.getProgress(), 100);
}


TEST(Badge, UpdateLockedStatus) {
    BadgeTest b("", "", "", rand() % 100, true);
    ASSERT_TRUE(b.isLocked());
    ASSERT_FALSE(b.updateLockedStatus());
    ASSERT_TRUE(b.isLocked());
    b.setPoints(rand() % 100 + 100);
    ASSERT_TRUE(b.isLocked());
    ASSERT_TRUE(b.updateLockedStatus());
    ASSERT_FALSE(b.isLocked());
    ASSERT_FALSE(b.updateLockedStatus());
    ASSERT_FALSE(b.isLocked());
}

//
// Created by Lorenzo Nuti and Paolo Valcepina on 10/07/17.
//

#include "../Background.h"

#include <gtest/gtest.h>

TEST(Background, Constructor) {
    ModelGame m;
    Background b(m);
    ASSERT_EQ(b.getShift(), 0);
    ASSERT_EQ(b.getVel(), -500);
    ASSERT_EQ(b.getDistance(), 0);
}

TEST(Background, Update) {
    ModelGame m;
    Background b(m);
    for (int i = 0; i < 3; i++) {
        float distance = b.getDistance();
        float time = Window::getInstance()->getElapsed();
        b.update();
        ASSERT_FLOAT_EQ(b.getShift(), b.getVel() * time);
        ASSERT_FLOAT_EQ(b.getDistance(), distance - b.getShift() / 100);
    }
}


TEST(Background, Draw) {
    ModelGame m;
    Background b(m);
    b.draw();
    ASSERT_EQ(b.getShift(), 0);
    ASSERT_EQ(b.getVel(), -500);
    ASSERT_EQ(b.getDistance(), 0);
}

TEST(Background, Vel) {
    ModelGame m;
    Background b(m);
    float p;
    for (int i = 0; i < 3; i++) {
        p = std::rand() % 20000 - 10000;
        b.setVel(p);
        ASSERT_FLOAT_EQ(b.getVel(), p);
    }
}

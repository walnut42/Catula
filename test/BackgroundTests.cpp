//
// Created by Lorenzo Nuti and Paolo Valcepina on 10/07/17.
//

#include "gtest/gtest.h"

#include "../Background.h"


TEST(Background, Constructor) {
    ModelGame m;
    Background b(m);
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

//
// Created by Lorenzo Nuti and Paolo Valcepina on 10/07/17.
//

#include "gtest/gtest.h"

#include "../BadgeDeath.h"
#include "../MainCharacter.h"



TEST(Badge, Attach) {
    ModelGame m;
    MainCharacter mC = MainCharacter(m, Image::Catula);
    BadgeDeath b("", "", "", 3, true);
    mC.increaseLives(1);
    b.attach(&mC);
    ASSERT_FLOAT_EQ(b.getProgress(), 0);
    mC.increaseLives(-1);
    ASSERT_FLOAT_EQ(b.getProgress(), 100/3.);
    mC.increaseLives(-2);
    ASSERT_FLOAT_EQ(b.getProgress(), 300/3.);
    //Assert detach
    mC.increaseLives(-1);
    ASSERT_FLOAT_EQ(b.getProgress(), 300/3.);
}

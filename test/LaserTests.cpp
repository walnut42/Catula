//
// Created by Lorenzo Nuti and Paolo Valcepina on 12/07/17.
//


#include <gtest/gtest.h>
#include "../ModelGame.h"
#include "../Laser.h"
#include "../MainCharacter.h"


class TestLaser : public Laser {
public:
    TestLaser(ModelGame &modelGame, float x, float y) : Laser(modelGame, x, y) {};

    const sf::Vector2f &getOriginPos() {
        return originPos;
    }

    const sf::Vector2f &getRelPos() const {
        return relPos;
    }

    const sf::Vector2f &getRelVel() const {
        return relVel;
    }

    const sf::Vector2f &getAcc() const {
        return acc;
    }
};


TEST(Laser, Constructor) {
    ModelGame model;
    TestLaser laser(model, 30, 50);
    ASSERT_FLOAT_EQ(laser.getOriginPos().x, 30);
    ASSERT_GE(laser.getOriginPos().y, 0);
    ASSERT_LE(laser.getOriginPos().y, Window::getHeight());
    ASSERT_FLOAT_EQ(laser.getAngleVel(), 50);
    ASSERT_FLOAT_EQ(laser.getAcc().x, 0);
    ASSERT_FLOAT_EQ(laser.getAcc().y, 0);
}

TEST(Laser, Update) {
    ModelGame model;
    TestLaser laser(model, 30, 50);
    for (int i = 0; i != 3; i++) {
        sf::Vector2f relVel = laser.getRelVel();
        sf::Vector2f relPos = laser.getRelPos();
        laser.update();
        float time = Window::getInstance()->getElapsed();
        ASSERT_FLOAT_EQ(laser.getRelVel().x, relVel.x + laser.getAcc().x * time);
        ASSERT_FLOAT_EQ(laser.getRelVel().y, relVel.y + laser.getAcc().y * time);
        ASSERT_FLOAT_EQ(laser.getRelPos().x, relPos.x + laser.getRelVel().x * time);
        ASSERT_FLOAT_EQ(laser.getRelPos().y, relPos.y + laser.getRelVel().y * time);
    }
}


TEST(Laser, Collided) {
    ModelGame model;
    TestLaser laser(model, 30, 50);
    int lives = model.getMainCharacter()->getLives();
    laser.collided();
    ASSERT_TRUE(laser.getRemoveFlag());
    ASSERT_EQ(model.getMainCharacter()->getLives(), lives - 1);
}
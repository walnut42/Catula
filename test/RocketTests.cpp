//
// Created by Lorenzo Nuti and Paolo Valcepina on 12/07/17.
//


#include <gtest/gtest.h>
#include "../ModelGame.h"
#include "../Rocket.h"
#include "../MainCharacter.h"


class TestRocket : public Rocket {
public:
    TestRocket(ModelGame &modelGame, float x, float y) : Rocket(modelGame, x, y) {};

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


TEST(Rocket, Constructor) {
    ModelGame model;
    TestRocket rocket(model, 30, 50);
    ASSERT_FLOAT_EQ(rocket.getOriginPos().x, 30);
    ASSERT_GE(rocket.getOriginPos().y, 0);
    ASSERT_LE(rocket.getOriginPos().y, Window::getHeight());
    ASSERT_FLOAT_EQ(rocket.getRelVel().x, -600);
    ASSERT_FLOAT_EQ(rocket.getRelVel().y, -200);
    ASSERT_FLOAT_EQ(rocket.getAcc().y, 200);
}

TEST(Rocket, Update) {
    ModelGame model;
    TestRocket rocket(model, 30, 50);
    for (int i = 0; i != 3; i++) {
        sf::Vector2f relVel = rocket.getRelVel();
        sf::Vector2f relPos = rocket.getRelPos();
        rocket.update();
        float time = Window::getInstance()->getElapsed();
        ASSERT_FLOAT_EQ(rocket.getRelVel().x, relVel.x + rocket.getAcc().x * time);
        ASSERT_FLOAT_EQ(rocket.getRelVel().y, relVel.y + rocket.getAcc().y * time);
        ASSERT_FLOAT_EQ(rocket.getRelPos().x, relPos.x + rocket.getRelVel().x * time);
        ASSERT_FLOAT_EQ(rocket.getRelPos().y, relPos.y + rocket.getRelVel().y * time);
    }
}


TEST(Rocket, Collided) {
    ModelGame model;
    TestRocket rocket(model, 30, 50);
    model.getMainCharacter()->increaseScore(100);
    rocket.collided();
    ASSERT_TRUE(rocket.getRemoveFlag());
    ASSERT_EQ(model.getMainCharacter()->getScore() - 100, static_cast<int>(Score::Rocket));
}
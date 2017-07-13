//
// Created by Lorenzo Nuti and Paolo Valcepina on 12/07/17.
//


#include <gtest/gtest.h>
#include "../ModelGame.h"
#include "../Skull.h"
#include "../MainCharacter.h"


class TestSkull : public Skull {
public:
    TestSkull(ModelGame &modelGame, float x, float y) : Skull(modelGame, x, y) {};

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


TEST(Skull, Constructor) {
    ModelGame model;
    TestSkull skull(model, 30, 50);
    ASSERT_FLOAT_EQ(skull.getOriginPos().x, 30);
    ASSERT_GE(skull.getOriginPos().y, 0);
    ASSERT_LE(skull.getOriginPos().y, Window::getHeight());
    ASSERT_FLOAT_EQ(skull.getAcc().x, 0);
    ASSERT_FLOAT_EQ(skull.getAcc().y, 0);
}

TEST(Skull, Update) {
    ModelGame model;
    TestSkull skull(model, 30, 50);
    float time = 0;
    for (int i = 0; i != 3; i++) {
        skull.update();
        time += Window::getInstance()->getElapsed();
        ASSERT_FLOAT_EQ(skull.getRelVel().y, static_cast<float>(-900 * sin(3 * time)));
        ASSERT_FLOAT_EQ(skull.getRelPos().y, static_cast<float>(300 * cos(3 * time)));
    }
}


TEST(Skull, Collided) {
    ModelGame model;
    TestSkull skull(model, 30, 50);
    model.getMainCharacter()->increaseScore(100);
    skull.collided();
    ASSERT_TRUE(skull.getRemoveFlag());
    ASSERT_EQ(model.getMainCharacter()->getScore() - 100, static_cast<int>(Score::Skull));
}
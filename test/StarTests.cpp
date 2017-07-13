//
// Created by Lorenzo Nuti and Paolo Valcepina on 12/07/17.
//


#include <gtest/gtest.h>
#include "../ModelGame.h"
#include "../Star.h"
#include "../MainCharacter.h"
#include "../Window.h"


class TestStar : public Star {
public:
    TestStar(ModelGame &modelGame, float x, float y) : Star(modelGame, x, y) {};

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


TEST(Star, Constructor) {
    ModelGame model;
    TestStar star(model, 30, 50);
    ASSERT_FLOAT_EQ(star.getOriginPos().x, 30);
    ASSERT_FLOAT_EQ(star.getOriginPos().y, 50);
    ASSERT_FLOAT_EQ(star.getRelVel().x, 0);
    ASSERT_FLOAT_EQ(star.getRelVel().y, 10);
}

TEST(Star, Update) {
    ModelGame model;
    TestStar star(model, 30, 50);
    for (int i = 0; i != 3; i++) {
        sf::Vector2f relVel = star.getRelVel();
        sf::Vector2f relPos = star.getRelPos();
        star.update();
        float time = Window::getInstance()->getElapsed();
        ASSERT_FLOAT_EQ(star.getRelVel().x, relVel.x + star.getAcc().x * time);
        ASSERT_FLOAT_EQ(star.getRelVel().y, relVel.y + star.getAcc().y * time);
        ASSERT_FLOAT_EQ(star.getRelPos().x, relPos.x + star.getRelVel().x * time);
        ASSERT_FLOAT_EQ(star.getRelPos().y, relPos.y + star.getRelVel().y * time);
    }
}


TEST(Star, Collided) {
    ModelGame model;
    TestStar star(model, 30, 50);
    model.getMainCharacter()->increaseScore(100);
    star.collided();
    ASSERT_TRUE(star.getRemoveFlag());
    ASSERT_EQ(model.getMainCharacter()->getScore() - 100, static_cast<int>(Score::Star));
}
//
// Created by Lorenzo Nuti and Paolo Valcepina on 12/07/17.
//

#include "../Collidable.h"

#include <gtest/gtest.h>

#include "../Background.h"

class TestCollidable : public Collidable {
public:
    TestCollidable(ModelGame &modelGame, Image image, float x = 0, float y = 0) : Collidable(modelGame, image, x, y) {};

    virtual void collided() {

    }

    const sf::Vector2f &getOriginPos() {
        return originPos;
    }

    const sf::Vector2f &getRelPos() const {
        return relPos;
    }

    void setRelPos(const sf::Vector2f &relPos) {
        TestCollidable::relPos = relPos;
    }

};

TEST(Collidable, Constructor) {
    ModelGame model;
    TestCollidable a(model, Image::Laser, 30, 50);
    ASSERT_FLOAT_EQ(a.getPos().x, 30);
    ASSERT_FLOAT_EQ(a.getPos().y, 50);
    ASSERT_FLOAT_EQ(a.getOriginPos().x, 30);
    ASSERT_FLOAT_EQ(a.getOriginPos().y, 50);
}


TEST(Collidable, Update) {
    ModelGame model;
    TestCollidable a(model, Image::Laser, 30, 50);
    a.setRelPos({20, 15});
    for (int i = 0; i != 3; i++) {
        model.getBackground()->update();
        sf::Vector2f oPos = a.getOriginPos();
        a.update();
        ASSERT_FLOAT_EQ(a.getOriginPos().x, oPos.x + model.getBackground()->getShift());
        ASSERT_EQ(a.getPos(), a.getOriginPos() + a.getRelPos());
    }
}
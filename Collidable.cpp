//
// Created by Lorenzo Nuti and Paolo Valcepina on 26/03/17.
//

#include "Collidable.h"

#include "Background.h"
#include "MainCharacter.h"

Collidable::Collidable(ModelGame &modelGame, Image image, float x, float y) :
        Entity{modelGame, image, x, y} {
    originPos = sf::Vector2f(x, y);
}

void Collidable::update() {
    float shift = modelGame.getBackground()->getShift();
    originPos.x += shift;
    pos = originPos + relPos;
    vel.x = modelGame.getBackground()->getVel() + relVel.x;
    vel.y = relVel.y;

    if (pos.x + size.x < 0)
        removeFlag = true;

    if (modelGame.getMainCharacter()->collide(this))
        collided();
}

void Collidable::updateRelPos() {
    float seconds = Window::getInstance()->getElapsed();
    relVel += acc * seconds;
    relPos += relVel * seconds;
    angleVel += angleAcc * seconds;
    angle += angleVel * seconds;
}

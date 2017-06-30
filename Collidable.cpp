//
// Created by Lorenzo Nuti and Paolo Valcepina on 26/03/17.
//

#include "Collidable.h"

#include "Background.h"

Collidable::Collidable(const std::string &filename, float x, float y, sf::IntRect textureRect) :
        Entity(filename, x, y, textureRect) {
    originPos = sf::Vector2f(x, y);
}


void Collidable::update() {
    updateRelPos();
    float shift = Background::getInstance()->getShift();
    originPos.x += shift;
    pos = originPos + relPos;
    vel.x = Background::getInstance()->getVel() + relVel.x;
    vel.y = relVel.y;

    if (pos.x + size.x < 0)
        removeFlag = true;

    if (MainCharacter::getInstance()->collide(this))
        collided();
}

void Collidable::updateRelPos() {
    float seconds = Window::getInstance()->getElapsed();
    relVel += acc * seconds;
    relPos += relVel * seconds;
    angleVel += angleAcc * seconds;
    angle += angleVel * seconds;
}

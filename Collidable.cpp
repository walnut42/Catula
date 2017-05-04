//
// Created by Lorenzo Nuti and Paolo Valcepina on 26/03/17.
//

#include "Collidable.h"

#include "Background.h"
#include "MainCharacter.h"

Collidable::Collidable(float width, float height, float x, float y) : Entity(width, height, x, y) {
    originPos = sf::Vector2f(x, y);
}


void Collidable::update() {
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
    relVel.x += acc.x * seconds;
    relVel.y += acc.y * seconds;
    relPos.x += relVel.x * seconds;
    relPos.y += relVel.y * seconds;
}

//
// Created by Lorenzo Nuti and Paolo Valcepina on 26/03/17.
//

#include "Collidable.h"

#include "Background.h"
#include "MainCharacter.h"

Collidable::Collidable(Window *window, Background *background, MainCharacter *maincharacter,
                       const std::string &filename, float x, float y, sf::IntRect textureRect) :
        Entity(window, filename, x, y, textureRect), background{background}, maincharacter{maincharacter} {
    originPos = sf::Vector2f(x, y);
}


void Collidable::update() {
    updateRelPos();
    float shift = background->getShift();
    originPos.x += shift;
    pos = originPos + relPos;
    vel.x = background->getVel() + relVel.x;
    vel.y = relVel.y;

    if (pos.x + size.x < 0)
        removeFlag = true;

    if (maincharacter->collide(this))
        collided();
}

void Collidable::updateRelPos() {
    float seconds = window->getElapsed();
    relVel += acc * seconds;
    relPos += relVel * seconds;
    angleVel += angleAcc * seconds;
    angle += angleVel * seconds;
}

//
// Created by Lorenzo Nuti and Paolo Valcepina on 26/03/17.
//

#include "Collidable.h"

#include "Background.h"
#include "MainCharacter.h"

Collidable::Collidable(float width, float height, float x, float y) : Entity(width, height, x, y) {
    originPos = sf::Vector2f(x, y);
    Window::getInstance()->add(this);
}

Collidable::~Collidable() {
    Window::getInstance()->remove(this);
}

void Collidable::update() {
    float shift = Background::getInstance()->getShift();
    originPos.x += shift;
    pos = originPos + relativePos;
    vel.x = shift / window->getElapsedTime().asSeconds() + relativeVel.x;
    vel.y = relativeVel.x;

    if (pos.x + size.x < 0)
        removeFlag = true;

    if (MainCharacter::getInstance()->collide(this))
        collided();
}

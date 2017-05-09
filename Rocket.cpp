//
// Created by lorenzo on 09/05/17.
//

#include "Rocket.h"
#include "Window.h"

Rocket::Rocket(float x, float y) : Collidable("../Resources/rocket.png", x, y) {
    relVel.x = -600;
    relVel.y = -200;
    acc.y = 200;
    sprite.setOrigin(size.x / 2, size.y / 2);
}

void Rocket::update() {
    relVel.y += acc.y * Window::getInstance()->getElapsed();
    relPos.y += relVel.y * Window::getInstance()->getElapsed();
    relPos.x += relVel.x * Window::getInstance()->getElapsed();
    angle = atan2(-relVel.y, -relVel.x) * 180 / M_PI;

    Collidable::update();
}

void Rocket::collided() {
    removeFlag = true;
}
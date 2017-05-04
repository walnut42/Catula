//
// Created by lorenzo on 04/05/17.
//

#include "Laser.h"
#include "Window.h"

Laser::Laser(float x, float y) : Collidable(30, 5, x, y) {
    // Shape initialization
    texture.loadFromFile("../Resources/laser.png");
    sprite.setTexture(texture);
    //relVel.y = 6;
    angVel = 0.5;
    sprite.setOrigin(200, 0);
}

void Laser::update() {
    relPos.y += relVel.y * Window::getInstance()->getElapsed();
    angle += angVel;

    if (relPos.y > 10 || relPos.y < -10)
        relVel.y *= -1;
    Collidable::update();
}

void Laser::collided() {
    removeFlag = true;
}
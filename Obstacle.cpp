//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#include "Obstacle.h"
#include "Window.h"

Obstacle::Obstacle(float x, float y) : Collidable(10, 10, x, y) {
    // Shape initialization
    texture.loadFromFile("../Resources/star.png");
    sprite.setTexture(texture);
    relVel.y = 6;
}

void Obstacle::update() {
    relPos.y += relVel.y * Window::getInstance()->getElapsed();

    if (relPos.y > 10 || relPos.y < -10)
        relVel.y *= -1;
    Collidable::update();
}

void Obstacle::collided() {
    removeFlag = true;
}
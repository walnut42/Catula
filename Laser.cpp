//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/05/17.
//

#include "Laser.h"
#include "Window.h"
#include "MainCharacter.h"

Laser::Laser(float x, float y) : Collidable("../Resources/laser.png", x, y) {
    angleVel = 0.5;
    sprite.setOrigin(size.x / 2, size.y / 2);
}

void Laser::update() {
    relPos.y += relVel.y * Window::getInstance()->getElapsed();
    angle += angleVel;

    Collidable::update();
}

void Laser::collided() {
    removeFlag = true;
    MainCharacter::getInstance()->increaseScore(-1);
}
//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/05/17.
//

#include "Laser.h"
#include "Window.h"
#include "MainCharacter.h"

Laser::Laser(float x, float y) : Collidable("../Resources/laser.png", x, y) {
    angleVel = 50;
    sprite.setOrigin(size.x / 2, size.y / 2);
}

void Laser::collided() {
    removeFlag = true;
    MainCharacter::getInstance()->increaseLife(-1);
}
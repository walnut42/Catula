//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/05/17.
//

#include "Laser.h"

#include "MainCharacter.h"

Laser::Laser(ModelGame &modelGame, float x, float y) : Collidable{modelGame, Image::Laser, x, y} {
    angleVel = 50;
    sprite.setOrigin(size.x / 2, size.y / 2);
    originPos.y = std::rand() % (static_cast<int>(Window::getHeight() - size.x / 2));
    pos.y = originPos.y;
}

void Laser::update() {
    updateRelPos();
    Collidable::update();
}

void Laser::collided() {
    removeFlag = true;
    modelGame.getMainCharacter()->increaseLives(-1);
    modelGame.getMainCharacter()->playSound(Sound::Laser);
}

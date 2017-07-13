//
// Created by Lorenzo Nuti and Paolo Valcepina on 05/07/17.
//

#include "Skull.h"

#include "MainCharacter.h"

Skull::Skull(ModelGame &modelGame, float x, float y) : Collidable{modelGame, Image::Skull, x, y}, time{0} {
    relVel.y = 500;
    originPos.y = std::rand() % (static_cast<int>(Window::getHeight() - 3 * size.y)) + size.y;
    pos.y = originPos.y;
}

void Skull::update() {
    time += Window::getInstance()->getElapsed();
    relPos.y = static_cast<float>(300 * cos(3 * time));
    relVel.y = static_cast<float>(-900 * sin(3 * time));

    Collidable::update();
}

void Skull::collided() {
    removeFlag = true;
    modelGame.getMainCharacter()->increaseScore(static_cast<int>(Score::Skull));
    modelGame.getMainCharacter()->playSound(Sound::Zombie);
}
//
// Created by Lorenzo Nuti and Paolo Valcepina on 05/07/17.
//

#include "Skull.h"

#include "MainCharacter.h"
#include "Window.h"

Skull::Skull(ModelGame &modelGame, float x, float y) : Collidable{modelGame, Image::Skull, x, y}, time{0} {
    relVel.y = 500;
}

void Skull::update() {
//    relPos.y += relVel.y * Window::getInstance()->getElapsed();
//
//    if (relPos.y > 500 || relPos.y < -500)
//        relVel.y *= -1;
//    updateRelPos();

    time += Window::getInstance()->getElapsed();
    relPos.y = static_cast<float>(300 * cos(3 * time));
    relVel.y = static_cast<float>(-900 * sin(3 * time));

    Collidable::update();
}

void Skull::collided() {
    removeFlag = true;
    modelGame.getMainCharacter()->increaseScore(5);
    modelGame.getMainCharacter()->playSound(Sound::Bonus);
}
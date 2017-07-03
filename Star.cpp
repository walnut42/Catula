//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#include "Star.h"
#include "Window.h"
#include "MainCharacter.h"

Star::Star(ModelGame &modelGame, float x, float y) : Collidable(modelGame, Image::Star, x, y) {
    relVel.y = 6;
}

void Star::update() {
    relPos.y += relVel.y * Window::getInstance()->getElapsed();

    if (relPos.y > 10 || relPos.y < -10)
        relVel.y *= -1;
    Collidable::update();
}

void Star::collided() {
    removeFlag = true;
    modelGame.increaseScore(1);
    modelGame.getMainCharacter()->playSound(Sound::Bonus);
}
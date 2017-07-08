//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#include "Star.h"

#include "MainCharacter.h"

Star::Star(ModelGame &modelGame, float x, float y) : Collidable{modelGame, Image::Star, x, y} {
    relVel.y = 10;
}

void Star::update() {
    if (relPos.y > 15 || relPos.y < -15)
        relVel.y *= -1;

    updateRelPos();
    Collidable::update();
}

void Star::collided() {
    removeFlag = true;
    modelGame.getMainCharacter()->increaseScore(static_cast<int>(Score::Star));
    modelGame.getMainCharacter()->playSound(Sound::Bonus);
}
//
// Created by Lorenzo Nuti and Paolo Valcepina on 09/05/17.
//

#include "Rocket.h"

#include "MainCharacter.h"

Rocket::Rocket(ModelGame &modelGame, float x, float y) : Collidable{modelGame, Image::Rocket, x, y} {
    relVel.x = -600;
    relVel.y = -200;
    acc.y = 200;
    sprite.setOrigin(size.x / 2, size.y / 2);
    float maxHeight = relVel.y * relVel.y / (2 * acc.y);
    int randPos = std::rand() % (static_cast<int>(Window::getHeight() - maxHeight - size.y));
    originPos.y = randPos + maxHeight;
    pos.y = originPos.y;
}

void Rocket::update() {
    angle = static_cast<float>(atan2(-relVel.y, -relVel.x) * 180 / M_PI);

    updateRelPos();
    Collidable::update();
}

void Rocket::collided() {
    removeFlag = true;
    modelGame.getMainCharacter()->increaseScore(static_cast<int>(Score::Rocket));
    modelGame.getMainCharacter()->playSound(Sound::Explosion);
}
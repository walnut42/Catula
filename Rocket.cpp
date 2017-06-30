//
// Created by Lorenzo Nuti and Paolo Valcepina on 09/05/17.
//

#include "Rocket.h"
#include "Window.h"
#include "MainCharacter.h"

Rocket::Rocket(ModelGame &modelGame, float x, float y) : Collidable(modelGame, "../Resources/rocket.png", x, y) {
    relVel.x = -600;
    relVel.y = -200;
    acc.y = 200;
    sprite.setOrigin(size.x / 2, size.y / 2);
}

void Rocket::update() {
    angle = static_cast<float>(atan2(-relVel.y, -relVel.x) * 180 / M_PI);

    Collidable::update();
}

void Rocket::collided() {
    removeFlag = true;
    modelGame.getMainCharacter()->increaseScore(5);
}
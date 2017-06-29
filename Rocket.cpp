//
// Created by Lorenzo Nuti and Paolo Valcepina on 09/05/17.
//

#include "Rocket.h"
#include "MainCharacter.h"

Rocket::Rocket(Window *window, Background *background, MainCharacter *maincharacter, float x, float y) : Collidable(
        window, background, maincharacter, "../Resources/rocket.png", x, y) {
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
    maincharacter->increaseScore(5);
}
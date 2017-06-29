//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#include "Star.h"
#include "Window.h"
#include "MainCharacter.h"

Star::Star(Background *background, MainCharacter *maincharacter, float x, float y) : Collidable(
        background, maincharacter, "../Resources/star.png", x, y) {
    relVel.y = 6;
}

void Star::update(float elapsed) {
    relPos.y += relVel.y * elapsed;

    if (relPos.y > 10 || relPos.y < -10)
        relVel.y *= -1;
    Collidable::update(elapsed);
}

void Star::collided() {
    removeFlag = true;
    maincharacter->increaseScore(1);
}
//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/04/17.
//

#include "CollidableFactory.h"

#include "Star.h"
#include "Window.h"
#include "Laser.h"
#include "Rocket.h"

Collidable *CollidableFactory::createCollidable(Background *background, MainCharacter *maincharacter) {
    // TODO others collidable objects
    int p = rand() % 100;
    if (p < 20)
        return new Rocket(background, maincharacter, Model::getWidth(),
                          rand() % ((int) Model::getHeight() - 300) + 100);
    else if (p < 60)
        return new Star(background, maincharacter, Model::getWidth(),
                        rand() % ((int) Model::getHeight() - 300) + 100);
    else
        return new Laser(background, maincharacter, Model::getWidth(),
                         rand() % ((int) Model::getHeight() - 300) + 100);

}

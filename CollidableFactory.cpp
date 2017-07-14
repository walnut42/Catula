//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/04/17.
//

#include "CollidableFactory.h"

#include "Laser.h"
#include "Rocket.h"
#include "Skull.h"
#include "Star.h"

Collidable *CollidableFactory::createCollidable(ModelGame &modelGame) {
    int p = std::rand() % 100;
    if (p < 20)
        return new Rocket(modelGame);
    else if (p < 40)
        return new Skull(modelGame);
    else if (p < 70)
        return new Star(modelGame);
    else
        return new Laser(modelGame);
}

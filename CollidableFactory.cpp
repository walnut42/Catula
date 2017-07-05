//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/04/17.
//

#include "CollidableFactory.h"

#include "Laser.h"
#include "Rocket.h"
#include "Skull.h"
#include "Star.h"
#include "Window.h"

Collidable *CollidableFactory::createCollidable(ModelGame &modelGame) {
    int p = rand() % 100;
    if (p < 20)
        return new Rocket(modelGame, Window::getWidth(), rand() % ((int) Window::getHeight() - 300) + 100);
    else if (p < 40)
        return new Skull(modelGame, Window::getWidth(), rand() % ((int) Window::getHeight() - 300) + 100);
    else if (p < 70)
        return new Star(modelGame, Window::getWidth(), rand() % ((int) Window::getHeight() - 300) + 100);
    else
        return new Laser(modelGame, Window::getWidth(), rand() % ((int) Window::getHeight() - 300) + 100);
}

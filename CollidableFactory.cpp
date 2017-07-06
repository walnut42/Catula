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
    int p = std::rand() % 100;
    if (p < 20)
        return new Rocket(modelGame, Window::getWidth(), std::rand() % ((int) Window::getHeight() - 300) + 100);
    else if (p < 40)
        return new Skull(modelGame, Window::getWidth(), std::rand() % ((int) Window::getHeight() - 300) + 100);
    else if (p < 70)
        return new Star(modelGame, Window::getWidth(), std::rand() % ((int) Window::getHeight() - 300) + 100);
    else
        return new Laser(modelGame, Window::getWidth(), std::rand() % ((int) Window::getHeight() - 300) + 100);
}

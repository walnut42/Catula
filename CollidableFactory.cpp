//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/04/17.
//

#include "CollidableFactory.h"

#include "Star.h"
#include "Window.h"
#include "Laser.h"
#include "Rocket.h"

Collidable *CollidableFactory::createCollidable(ModelGame &modelGame) {
    int p = rand() % 100;
    if (p < 20)
        return new Rocket(modelGame, Window::getWidth(), rand() % ((int) Window::getHeight() - 300) + 100);
    else if (p < 60)
        return new Star(modelGame, Window::getWidth(), rand() % ((int) Window::getHeight() - 300) + 100);
    else
        return new Laser(modelGame, Window::getWidth(), rand() % ((int) Window::getHeight() - 300) + 100);

}

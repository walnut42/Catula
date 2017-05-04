//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/04/17.
//

#include "CollidableFactory.h"

#include "Obstacle.h"
#include "Window.h"
#include "Laser.h"

Collidable *CollidableFactory::createCollidable() {
    // TODO others collidable objects
    int p = rand() % 100;
    if (p < 10)
        return new Obstacle(Window::getInstance()->getWidth(), rand() % (100 - 30) + 10);
    else
        return new Laser(Window::getInstance()->getWidth(), rand() % (100 - 30) + 10);

}

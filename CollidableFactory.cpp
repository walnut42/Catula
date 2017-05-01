//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/04/17.
//

#include "CollidableFactory.h"

#include "Obstacle.h"
#include "Window.h"

Collidable *CollidableFactory::createCollidable() {
    // TODO others collidable objects
    // if (cond1)
    //    new Obstacle
    // elseif (cond2)
    //    new ChickenWing

    return new Obstacle(Window::getInstance()->getWidth(), rand() % (100 - 30) + 10);
}

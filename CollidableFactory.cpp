//
// Created by paolo on 30/04/17.
//

#include "CollidableFactory.h"
#include "Obstacle.h"

Collidable *CollidableFactory::getInstance() {
    // TODO others collidable objects
    // if (cond1)
    //    new Obstacle
    // elseif (cond2)
    //    new ChickenWing

    return new Obstacle(Window::getInstance()->getWidth(), rand() % (100 - 30) + 10);
}

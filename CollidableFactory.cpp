//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/04/17.
//

#include "CollidableFactory.h"

#include "Obstacle.h"
#include "Window.h"
#include "Laser.h"
#include "Rocket.h"

Collidable *CollidableFactory::createCollidable() {
    // TODO others collidable objects
    int p = rand() % 100;
    if (p < 100)
        return new Rocket(Window::getWidth(), rand() % ((int) Window::getHeight() - 300) + 100);
    else if (p < 50)
        return new Obstacle(Window::getWidth(), rand() % ((int) Window::getHeight() - 300) + 100);
    else
        return new Laser(Window::getWidth(), rand() % ((int) Window::getHeight() - 300) + 100);

}

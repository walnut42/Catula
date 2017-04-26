//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#include "Obstacle.h"

Obstacle::Obstacle(float x, float y) : Collidable(10, 10, x, y) {
    // Shape initialization
    texture.loadFromFile("../Resources/star.png");
    sprite.setTexture(texture);
    relativeVel.y = 6;
}

void Obstacle::update(const sf::Time &elapsed) {
    relativePos.y += relativeVel.y * elapsed.asSeconds();

    if (relativePos.y > 10 || relativePos.y < -10)
        relativeVel.y *= -1;
    Collidable::update(elapsed);
}

void Obstacle::collided() {
    removeFlag = true;
}
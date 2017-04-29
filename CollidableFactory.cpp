//
// Created by Lorenzo Nuti and Paolo Valcepina on 26/03/17.
//

#include "CollidableFactory.h"

#include "Obstacle.h"

std::list<Collidable *> CollidableFactory::collidables;

void CollidableFactory::update() {
    removeCollidables();

    if (collidables.empty() || collidables.back()->getPos().x < 200 * 2 / 3)
        createCollidable();
}

Collidable *CollidableFactory::createCollidable() {
    // random generation
    collidables.push_back(new Obstacle(200, rand() % (100 - 30) + 10));
    return collidables.back();
}

void CollidableFactory::removeCollidables() {
    for (auto it = collidables.begin(), end = collidables.end(); it != end;) {
        // Updating the iterator before it's cancelled avoids to have a null iterator
        if ((*it)->getRemoveFlag()) {
            auto prev = it++;
            delete *prev;
            collidables.erase(prev);
        } else
            ++it;
    }
}

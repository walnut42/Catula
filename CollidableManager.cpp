//
// Created by Lorenzo Nuti and Paolo Valcepina on 26/03/17.
//

#include "CollidableManager.h"

std::list<Collidable *> CollidableManager::collidables;

void CollidableManager::update() {
    removeCollidables();

    if (collidables.empty() || collidables.back()->getPos().x < Window::getInstance()->getProportions() - 100) {
        collidables.push_back(CollidableFactory::createCollidable());
    }
}

void CollidableManager::removeCollidables() {
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

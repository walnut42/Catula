//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/06/17.
//

#include "ModelGame.h"
#include "Window.h"


void ModelGame::update() {
    removeCollidables();

    if (collidables.empty() || collidables.back()->getPos().x < Window::getWidth() - 1000) {
        collidables.push_back(CollidableFactory::createCollidable());
    }
}

void ModelGame::removeCollidables() {
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
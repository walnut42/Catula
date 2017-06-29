//
// Created by lorenzo on 29/06/17.
//

#include "Model.h"

const float Model::width = 4000;
const float Model::height = 1000;


Model::Model() : background{new Background}, mainCharacter{new MainCharacter} {

}

const float Model::getWidth() {
    return width;
}

const float Model::getHeight() {
    return height;
}

void Model::removeCollidables() {
    for (auto it = collidables.begin(), end = collidables.end(); it != end;) {
        if ((*it)->getRemoveFlag()) {
            auto prev = it++;
            collidables.erase(prev);
        } else
            ++it;
    }
}

void Model::draw(Window *window) {
    background->draw(window);
    mainCharacter->draw(window);
    for (auto &coll : collidables) {
        coll->draw(window);
    }
}

void Model::update(float elapsed) {
    background->update(elapsed);
    mainCharacter->update(elapsed);
    for (auto &coll : collidables) {
        coll->update(elapsed);
    }
}


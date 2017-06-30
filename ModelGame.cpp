//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/06/17.
//

#include "ModelGame.h"
#include "Window.h"
#include "CollidableFactory.h"
#include "Background.h"
#include "MainCharacter.h"
#include "ModelMenu.h"


ModelGame::ModelGame() {
    background = new Background(*this);
    mainCharacter = new MainCharacter(*this);
    textbox = new Textbox(*this);
}

ModelGame::~ModelGame() {
    delete background;
    delete mainCharacter;
    delete textbox;
}

ModelBase *ModelGame::update() {
    removeCollidables();

    if (collidables.empty() || collidables.back()->getPos().x < Window::getWidth() - 1000) {
        collidables.push_back(CollidableFactory::createCollidable(*this));
    }

    background->update();
    mainCharacter->update();
    for (auto &coll:collidables) {
        coll->update();
    }
    textbox->update();
    return nullptr;
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

void ModelGame::draw() {
    background->draw();
    mainCharacter->draw();
    for (auto &coll:collidables) {
        coll->draw();
    }
    textbox->draw();
}


ModelBase *ModelGame::processInput(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        return new ModelMenu();
    else
        return nullptr;
}

Background *ModelGame::getBackground() {
    return background;
}

MainCharacter *ModelGame::getMainCharacter() {
    return mainCharacter;
}

const std::list<Collidable *> &ModelGame::getCollidables() const {
    return collidables;
}

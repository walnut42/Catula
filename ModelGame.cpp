//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/06/17.
//

#include "ModelGame.h"

#include "Window.h"
#include "CollidableFactory.h"
#include "Background.h"
#include "MainCharacter.h"
#include "BadgesManager.h"

ModelGame::ModelGame() : ModelGame{Image::Catula} {}

ModelGame::ModelGame(Image image) {
    Audio::setMusic(music, Music::Game);
    music.setLoop(true);

    background = new Background(*this);
    mainCharacter = new MainCharacter(*this, image);
    textbox = new GameInfo(*this);

    BadgesManager::createBadgesObservers(mainCharacter);
}

ModelGame::~ModelGame() {
    BadgesManager::destroyBadgesObservers();
    delete background;
    delete mainCharacter;
    delete textbox;
}

ModelBase *ModelGame::processInput(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        return getModel(Controller::modelPause);
    else
        return nullptr;
}

ModelBase *ModelGame::update() {
    removeCollidables();

    // Use pixel instead of number of collidable objects because of playability on different screen widths.
    if (collidables.empty() || collidables.back()->getPos().x < Window::getWidth() * -1000) {
        collidables.push_back(std::unique_ptr<Collidable>(CollidableFactory::createCollidable(*this)));
    }

    background->update();
    mainCharacter->update();
    for (auto &coll:collidables) {
        coll->update();
    }
    textbox->update();

    if (mainCharacter->hasLost())
        return getModel(Controller::modelGameOver);

    return nullptr;
}

void ModelGame::draw() {
    background->draw();
    mainCharacter->draw();
    for (auto &coll:collidables) {
        coll->draw();
    }
    textbox->draw();
}

void ModelGame::enter() {
    music.play();
}

void ModelGame::exit() {
    music.pause();
}

Background *ModelGame::getBackground() {
    return background;
}

MainCharacter *ModelGame::getMainCharacter() {
    return mainCharacter;
}

void ModelGame::removeCollidables() {
    for (auto it = collidables.begin(), end = collidables.end(); it != end;) {

        // Updating the iterator before it's cancelled avoids to have a null iterator.
        if ((*it)->getRemoveFlag()) {
            auto prev = it++;
            collidables.erase(prev);
        } else
            ++it;
    }
}

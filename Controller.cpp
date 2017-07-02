//
// Created by Lorenzo Nuti and Paolo Valcepina on 26/03/17.
//


#include "Controller.h"


std::unique_ptr<ModelMenu> Controller::modelMenu;
std::unique_ptr<ModelGame> Controller::modelGame;
std::unique_ptr<ModelPause> Controller::modelPause;
std::unique_ptr<ModelGameOver> Controller::modelGameOver;


Controller::Controller() {
    changeModel(newModel(Controller::modelMenu));
}

void Controller::processInput(const sf::Event &event) {
    changeModel(activeModel->processInput(event));
}

void Controller::update() {
    changeModel(activeModel->update());
}

void Controller::draw() {
    activeModel->draw();
}

void Controller::changeModel(ModelBase *newModel) {
    if (newModel != nullptr) {
        activeModel = newModel;
        activeModel->enter();
    }
}



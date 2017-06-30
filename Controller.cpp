//
// Created by Lorenzo Nuti and Paolo Valcepina on 26/03/17.
//


#include "Controller.h"
#include "ModelMenu.h"


Controller::Controller() {
    activeModel = new ModelMenu();
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
        if (activeModel != nullptr)
            delete activeModel;
        activeModel = newModel;
    }
}

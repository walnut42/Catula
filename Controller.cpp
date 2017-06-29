//
// Created by Lorenzo Nuti and Paolo Valcepina on 26/03/17.
//

#include "Controller.h"


Controller::Controller(Model &model) : model{model} {

}

void Controller::update(float elapsed) {
    model.removeCollidables();

    if (model.collidables.empty() || model.collidables.back()->getPos().x < Model::getWidth() - 1000) {
        model.collidables.push_back(
                std::unique_ptr<Collidable>(
                        CollidableFactory::createCollidable(model.background, model.mainCharacter)));
    }

    model.update(elapsed);

}

void Controller::processInput(sf::Event event) {

}

void Controller::draw(Window *window) {
    model.draw(window);
}

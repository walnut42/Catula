//
// Created by Lorenzo Nuti and Paolo Valcepina on 26/03/17.
//

#ifndef CATULA_OBSTACLES_H
#define CATULA_OBSTACLES_H

#include <list>

#include "Background.h"
#include "MainCharacter.h"
#include "Collidable.h"
#include "CollidableFactory.h"


class Controller {
public:
    void processInput(const sf::Event &event) {
        activeModel->processInput(event);
    }

    void update() {
        activeModel->notifyUpdate();
    }

    void draw() {
        activeModel->notifyDraw();
    }

private:
    ModelBase *activeModel;

};


#endif //CATULA_OBSTACLES_H

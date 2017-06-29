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
#include "Model.h"

class Model;

class Controller {
public:
    Controller(Model &model);

    void update(float elapsed);

    void processInput(sf::Event event);

    void draw(Window *window);
private:
    Model &model;
};


#endif //CATULA_OBSTACLES_H



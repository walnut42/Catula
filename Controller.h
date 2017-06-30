//
// Created by Lorenzo Nuti and Paolo Valcepina on 26/03/17.
//

#ifndef CATULA_OBSTACLES_H
#define CATULA_OBSTACLES_H

#include <SFML/Graphics.hpp>
#include "ModelBase.h"

class Controller {
public:
    Controller();

    void processInput(const sf::Event &event);

    void update();

    void draw();

private:
    ModelBase *activeModel;

    void changeModel(ModelBase *newModel);
};


#endif //CATULA_OBSTACLES_H

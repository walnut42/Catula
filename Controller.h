//
// Created by Lorenzo Nuti and Paolo Valcepina on 26/03/17.
//

#ifndef CATULA_OBSTACLES_H
#define CATULA_OBSTACLES_H

#include <SFML/Graphics.hpp>
#include "ModelBase.h"
#include "ModelMenu.h"
#include "ModelGame.h"
#include "ModelPause.h"

class Controller {
public:
    Controller();

    void processInput(const sf::Event &event);

    void update();

    void draw();

    static std::unique_ptr<ModelMenu> modelMenu;
    static std::unique_ptr<ModelGame> modelGame;
    static std::unique_ptr<ModelPause> modelPause;

private:
    ModelBase *activeModel;

    void changeModel(ModelBase *newModel);
};


#endif //CATULA_OBSTACLES_H

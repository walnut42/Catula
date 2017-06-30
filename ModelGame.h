//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/06/17.
//

#ifndef CATULA_MODELGAME_H
#define CATULA_MODELGAME_H


#include "ModelBase.h"
#include "Collidable.h"

class ModelGame : public ModelBase {
public:
    ModelGame() {};

    ~ModelGame() {};

    void processInput(const sf::Event &event) override {};

    void update();

    void removeCollidables();

private:
    std::list<Collidable *> collidables;
};


#endif //CATULA_MODELGAME_H

//
// Created by Lorenzo Nuti and Paolo Valcepina on 09/05/17.
//

#ifndef CATULA_ROCKET_H
#define CATULA_ROCKET_H

#include "Collidable.h"


class Rocket : public Collidable {
public:
    explicit Rocket(ModelGame &modelGame, float x = Window::getWidth(), float y = 0);

    virtual void update() override;

    void collided() override;
};


#endif //CATULA_ROCKET_H

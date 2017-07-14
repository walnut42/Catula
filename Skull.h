//
// Created by Lorenzo Nuti and Paolo Valcepina on 05/07/17.
//

#ifndef CATULA_SKULL_H
#define CATULA_SKULL_H

#include "Collidable.h"


class Skull : public Collidable {
public:
    explicit Skull(ModelGame &modelGame, float x = Window::getWidth(), float y = 0);

    virtual void update() override;

    void collided() override;

private:
    float time;
};


#endif //CATULA_SKULL_H

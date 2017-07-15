//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#ifndef CATULA_OBSTACLE_H
#define CATULA_OBSTACLE_H

#include "Window.h"
#include "Collidable.h"


class Star : public Collidable {
public:
    explicit Star(ModelGame &modelGame, float x = Window::getWidth(), float y = 0);

    virtual void update() override;

    void collided() override;
};


#endif //CATULA_OBSTACLE_H
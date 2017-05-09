//
// Created by lorenzo on 09/05/17.
//

#ifndef CATULA_ROCKET_H
#define CATULA_ROCKET_H


#include "Collidable.h"

class Rocket : public Collidable {
public:
    Rocket(float x, float y);

    virtual void update() override;

    void collided() override;
};


#endif //CATULA_ROCKET_H

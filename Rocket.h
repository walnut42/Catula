//
// Created by Lorenzo Nuti and Paolo Valcepina on 09/05/17.
//

#ifndef CATULA_ROCKET_H
#define CATULA_ROCKET_H


#include "Collidable.h"

class Rocket : public Collidable {
public:
    Rocket(Background *background, MainCharacter *maincharacter, float x, float y);

    virtual void update(float elapsed) override;

    void collided() override;
};


#endif //CATULA_ROCKET_H

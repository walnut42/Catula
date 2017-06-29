//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/05/17.
//

#ifndef CATULA_LASER_H
#define CATULA_LASER_H


#include "Collidable.h"

class Laser : public Collidable {
public:
    Laser(Window *window, Background *background, MainCharacter *maincharacter, float x, float y);

    void collided() override;
};


#endif //CATULA_LASER_H

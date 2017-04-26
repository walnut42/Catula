//
// Created by Lorenzo Nuti and Paolo Valcepina on 26/03/17.
//

#ifndef CATULA_OBSTACLES_H
#define CATULA_OBSTACLES_H

#include <list>

#include "Background.h"
#include "MainCharacter.h"
#include "Collidable.h"


class CollidableFactory {
public:
    static void update();

    static Collidable *createCollidable();

    static void removeCollidables();

private:
    CollidableFactory() {};
    static std::list<Collidable *> collidables;
};


#endif //CATULA_OBSTACLES_H

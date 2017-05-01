//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/04/17.
//

#ifndef CATULA_COLLIDABLEFACTORY_H
#define CATULA_COLLIDABLEFACTORY_H


#include "Collidable.h"


class CollidableFactory {
public:
    static Collidable *createCollidable();

private:
    CollidableFactory() {};
};


#endif //CATULA_COLLIDABLEFACTORY_H

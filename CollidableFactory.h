//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/04/17.
//

#ifndef CATULA_COLLIDABLEFACTORY_H
#define CATULA_COLLIDABLEFACTORY_H


#include "Collidable.h"

class Collidable;

class Background;

class MainCharacter;
class CollidableFactory {
public:
    static Collidable *createCollidable(Background *background, MainCharacter *maincharacter);

private:
    CollidableFactory() {};
};


#endif //CATULA_COLLIDABLEFACTORY_H

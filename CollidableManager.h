//
// Created by Lorenzo Nuti and Paolo Valcepina on 26/03/17.
//

#ifndef CATULA_OBSTACLES_H
#define CATULA_OBSTACLES_H

#include <list>

#include "Background.h"
#include "MainCharacter.h"
#include "Collidable.h"
#include "CollidableFactory.h"


class CollidableManager {
public:
    static void update(Window *window, Background *background, MainCharacter *maincharacter);

    static void removeCollidables();

private:
    CollidableManager() {};
    static std::list<Collidable *> collidables;
};


#endif //CATULA_OBSTACLES_H



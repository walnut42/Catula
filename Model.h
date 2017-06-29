//
// Created by lorenzo on 29/06/17.
//

#ifndef CATULA_MODEL_H
#define CATULA_MODEL_H

#include "Background.h"
#include "MainCharacter.h"
#include "Collidable.h"

class Collidable;

class Background;

class Model {
public:
    Model();

    static const float getWidth();

    static const float getHeight();

    void removeCollidables();

    void update(float elapsed);

    void draw(Window *window);

    std::list<std::unique_ptr<Collidable>> &getCollidables();

    const Background *getBackground() const;

    Background *getBackground();

    const MainCharacter *getMainCharacter() const;

    MainCharacter *getMainCharacter();

private:
    std::list<std::unique_ptr<Collidable>> collidables;
    Background *background;
    MainCharacter *mainCharacter;
    static const float width;
    static const float height;
};


#endif //CATULA_MODEL_H

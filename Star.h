//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#ifndef CATULA_OBSTACLE_H
#define CATULA_OBSTACLE_H

#include "Collidable.h"

class Star : public Collidable {
public:
    Star(Background *background, MainCharacter *maincharacter, float x, float y);

    virtual void update(float elapsed) override;

    void collided() override;

private:
    sf::Texture texture;
};

#endif //CATULA_OBSTACLE_H
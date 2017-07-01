//
// Created by Lorenzo Nuti and Paolo Valcepina on 26/03/17.
//

#ifndef CATULA_COLLIDABLE_H
#define CATULA_COLLIDABLE_H

#include "Entity.h"

class ModelGame;

class Collidable : public Entity {
public:
    Collidable(ModelGame &modelGame, const std::string &filename, float x, float y,
               sf::IntRect textureRect = sf::IntRect());

    virtual ~Collidable() {};

    virtual void update() override;

    virtual void collided()=0;

    bool getRemoveFlag() {
        return removeFlag;
    }

protected:
    virtual void updateRelPos();

    bool removeFlag = false;
    sf::Vector2f originPos;
    sf::Vector2f relPos;
    sf::Vector2f relVel;
};


#endif //CATULA_COLLIDABLE_H

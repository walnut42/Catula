//
// Created by Lorenzo Nuti and Paolo Valcepina on 26/03/17.
//

#ifndef CATULA_COLLIDABLE_H
#define CATULA_COLLIDABLE_H

#include "Entity.h"

class Collidable : public Entity {
public:
    Collidable(float width, float height, float x, float y);

    virtual ~Collidable();

    virtual void update(const sf::Time &elapsed) override;

    virtual void collided()=0;

    bool getRemoveFlag() {
        return removeFlag;
    }

protected:
    bool removeFlag = false;
    sf::Vector2f originPos;
    sf::Vector2f relativePos;
    sf::Vector2f relativeVel;
};


#endif //CATULA_COLLIDABLE_H

//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#ifndef CATULA_ENTITY_H
#define CATULA_ENTITY_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "ModelGame.h"
#include "Images.h"

class Entity {
public:
    Entity(ModelGame &modelGame, Image image, float x = 0, float y = 0);

    virtual ~Entity() {};

    static bool collide(const Entity *obj1, const Entity *obj2);

    virtual void draw();

    virtual void update()=0;

    const sf::Vector2f getPos() const {
        return pos + sprite.getOrigin();
    }

    const sf::Vector2f &getVel() const {
        return vel;
    }

    float getAngle() const {
        return angle;
    }

    float getAngleVel() const {
        return angleVel;
    }

    sf::Sprite &getSprite() {
        return sprite;
    }

protected:
    virtual void getRelativePoints(std::vector<sf::Vector2f> &points) const;

    void updatePos();

    ModelGame &modelGame;

    sf::Sprite sprite;
    sf::Vector2f size;
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::Vector2f acc;
    float angle;
    float angleVel;
    float angleAcc;
private:
    void getAbsolutePoints(std::vector<sf::Vector2f> &points) const;

    static bool intersect(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3);

    static int ccw(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2);
};

#endif //CATULA_ENTITY_H
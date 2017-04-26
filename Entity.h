//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#ifndef CATULA_ENTITY_H
#define CATULA_ENTITY_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "Drawable.h"
#include "Window.h"

class Entity : public Drawable {
public:
    Entity();

    Entity(float width, float height, float x = 0, float y = 0);

    virtual ~Entity() {};

    static bool collide(const Entity *obj1, const Entity *obj2);

    virtual void draw(Window &window) override;

    const sf::Vector2f &getSize() const {
        return size;
    }

    const sf::Vector2f &getPos() const {
        return pos;
    }

    const sf::Vector2f &getVel() const {
        return vel;
    }

    sf::Sprite &getSprite() {
        return sprite;
    }

protected:
    void updatePos(const sf::Time &elapsed) {
        vel.x += acc.x * elapsed.asSeconds();
        vel.y += acc.y * elapsed.asSeconds();
        pos.x += vel.x * elapsed.asSeconds();
        pos.y += vel.y * elapsed.asSeconds();
    }

    sf::Vector2f size;
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::Vector2f acc;
    sf::Sprite sprite;
    float angle;
    float angVel;
    float angAcc;

private:
    static bool intersect(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3);

    static int ccw(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2);
};

#endif //CATULA_ENTITY_H
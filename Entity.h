//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#ifndef CATULA_ENTITY_H
#define CATULA_ENTITY_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "Drawable.h"


class Entity : public Drawable {
public:
    Entity(const std::string &filename, float x = 0, float y = 0, sf::IntRect textureRect = sf::IntRect());

    virtual ~Entity() {};

    static bool collide(const Entity *obj1, const Entity *obj2);

    virtual void draw() override;

    const sf::Vector2f getPos() const {
        return pos + sprite.getOrigin();
    }

    const sf::Vector2f &getVel() const {
        return vel;
    }

    sf::Sprite &getSprite() {
        return sprite;
    }

protected:
    virtual void getCollisionRect(std::vector<sf::Vector2f> &points) const;

    void updatePos();

    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f size;
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::Vector2f acc;
    float angle;
    float angVel;
    float angAcc;
private:
    void setTexture(const std::string &filename, sf::IntRect textureRect = sf::IntRect());

    static bool intersect(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3);

    static int ccw(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2);
};

#endif //CATULA_ENTITY_H
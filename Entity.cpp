//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#include "Entity.h"

#include "Window.h"

using namespace std;

Entity::Entity(ModelGame &modelGame, Image image, float x, float y) :
        modelGame{modelGame}, pos{x, y}, angle{0}, angleVel{0}, angleAcc{0} {

    Images::setSprite(sprite, image);
    sf::IntRect textureSize = sprite.getTextureRect();
    size = sf::Vector2f(textureSize.width, textureSize.height);
}

bool Entity::collide(const Entity *obj1, const Entity *obj2) {
    vector<sf::Vector2f> pObj1;
    obj1->getAbsolutePoints(pObj1);

    vector<sf::Vector2f> pObj2;
    obj2->getAbsolutePoints(pObj2);

    for (int i = 0; i < pObj2.size(); ++i) {
        for (int j = 0; j < pObj1.size(); ++j) {
            if (intersect(pObj2[i], pObj2[(i + 1) % pObj2.size()], pObj1[j], pObj1[(j + 1) % pObj1.size()]))
                return true;
        }
    }
    return false;
}

void Entity::draw() {
    Window::getInstance()->drawEntity(*this);
}


const sf::Vector2f Entity::getPos() const {
    return pos + sprite.getOrigin();
}

const sf::Vector2f &Entity::getVel() const {
    return vel;
}

float Entity::getAngle() const {
    return angle;
}

float Entity::getAngleVel() const {
    return angleVel;
}

sf::Sprite &Entity::getSprite() {
    return sprite;
}


void Entity::getRelativePoints(std::vector<sf::Vector2f> &points) const {
    // Points of a rectangle with a 0° angle
    points.clear();
    points.push_back(sf::Vector2f(0, 0));
    points.push_back(sf::Vector2f(size.x, 0));
    points.push_back(sf::Vector2f(size.x, size.y));
    points.push_back(sf::Vector2f(0, size.y));
}

void Entity::updatePos() {
    float seconds = Window::getInstance()->getElapsed();
    vel.x += acc.x * seconds;
    vel.y += acc.y * seconds;
    pos.x += vel.x * seconds;
    pos.y += vel.y * seconds;
}

void Entity::getAbsolutePoints(std::vector<sf::Vector2f> &points) const {
    getRelativePoints(points);

    //Angle-based point transformation and conversion to absolute points
    sf::Transform transform;
    transform.rotate(angle);
    sf::Vector2f originPos = sprite.getOrigin();
    for (sf::Vector2f &point:points) {
        point = transform.transformPoint(point - originPos) + pos + originPos;
    }
}

bool Entity::intersect(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3) {
    return ((ccw(p0, p1, p2) * ccw(p0, p1, p3)) <= 0) &&
           ((ccw(p2, p3, p0) * ccw(p2, p3, p1)) <= 0);
}

int Entity::ccw(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2) {
    float dx1, dx2, dy1, dy2;

    dx1 = p1.x - p0.x;
    dy1 = p1.y - p0.y;
    dx2 = p2.x - p0.x;
    dy2 = p2.y - p0.y;

    if (dx1 * dy2 > dy1 * dx2) return +1;
    if (dx1 * dy2 < dy1 * dx2) return -1;
    if ((dx1 * dx2 < 0) || (dy1 * dy2 < 0)) return -1;
    if ((dx1 * dx1 + dy1 * dy1) < (dx2 * dx2 + dy2 * dy2)) return +1;
    return 0;
}

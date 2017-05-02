//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#include "Entity.h"
#include "Window.h"

using namespace std;

Entity::Entity() : angle(0), angVel(0), angAcc(0) {

}

Entity::Entity(float width, float height, float x, float y) : Entity() {
    size = sf::Vector2f(width, height);
    pos = sf::Vector2f(x, y);
}

void Entity::draw() {
    Window::getInstance()->drawEntity(*this);
}

bool Entity::collide(const Entity *obj1, const Entity *obj2) {
    // Points of a rectangle with a 0° angle
    // TODO Collision with angle
    vector<sf::Vector2f> pObj;
    pObj.push_back(obj1->pos);
    pObj.push_back(sf::Vector2f(obj1->pos.x + obj1->size.x, obj1->pos.y));
    pObj.push_back(sf::Vector2f(obj1->pos.x + obj1->size.x, obj1->pos.y + obj1->size.y));
    pObj.push_back(sf::Vector2f(obj1->pos.x, obj1->pos.y + obj1->size.y));

    vector<sf::Vector2f> pThis;
    pThis.push_back(obj2->pos);
    pThis.push_back(sf::Vector2f(obj2->pos.x + obj2->size.x, obj2->pos.y));
    pThis.push_back(sf::Vector2f(obj2->pos.x + obj2->size.x, obj2->pos.y + obj2->size.y));
    pThis.push_back(sf::Vector2f(obj2->pos.x, obj2->pos.y + obj2->size.y));

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (intersect(pThis[i], pThis[(i + 1) % 4], pObj[j], pObj[(j + 1) % 4]))
                return true;
        }
    }
    return false;
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

void Entity::updatePos() {
    float seconds = Window::getInstance()->getElapsed();
    vel.x += acc.x * seconds;
    vel.y += acc.y * seconds;
    pos.x += vel.x * seconds;
    pos.y += vel.y * seconds;
}

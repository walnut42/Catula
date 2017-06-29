//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#include "Entity.h"
#include "Window.h"

using namespace std;

Entity::Entity(Window *window, const std::string &filename, float x, float y, sf::IntRect textureRect) : Drawable(
        window),
                                                                                                         angle(0),
                                                                                                         angleVel(0),
                                                                                                         angleAcc(0),
                                                                                                         pos(x, y) {
    setTexture(filename, textureRect);
}

void Entity::draw() {
    //Debug code: uncomment to see the red lines around the objects.
    /*
    vector<sf::Vector2f> pObj;
    getAbsolutePoints(pObj);
    sf::VertexArray lines(sf::LinesStrip, pObj.size() + 1);
    for (int i = 0; i <= pObj.size(); i++) {
        lines[i].position = pObj[i % pObj.size()];
        lines[i].color = sf::Color::Red;
    }
    Window::getInstance()->drawDrawable(lines);
    //End debug code */

    window->drawEntity(*this);
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
    float seconds = window->getElapsed();
    vel.x += acc.x * seconds;
    vel.y += acc.y * seconds;
    pos.x += vel.x * seconds;
    pos.y += vel.y * seconds;
}

void Entity::setTexture(const std::string &filename, sf::IntRect textureRect) {
    texture.loadFromFile(filename);
    texture.setSmooth(true);
    sprite.setTexture(texture);
    if (textureRect != sf::IntRect()) {
        sprite.setTextureRect(textureRect);
        size = sf::Vector2f(textureRect.width, textureRect.height);
    } else {
        sf::Vector2u textureSize = sprite.getTexture()->getSize();
        size = sf::Vector2f(textureSize.x, textureSize.y);
    }
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

void Entity::getRelativePoints(std::vector<sf::Vector2f> &points) const {
    // Points of a rectangle with a 0° angle
    points.clear();
    points.push_back(sf::Vector2f(0, 0));
    points.push_back(sf::Vector2f(size.x, 0));
    points.push_back(sf::Vector2f(size.x, size.y));
    points.push_back(sf::Vector2f(0, size.y));
}

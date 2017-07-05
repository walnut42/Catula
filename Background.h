//
// Created by Lorenzo Nuti and Paolo Valcepina on 17/03/17.
//

#ifndef CATULA_BACKGROUND_H
#define CATULA_BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <list>

#include "Window.h"


class ModelGame;

class Background {
public:
    Background(ModelGame &modelGame);

    virtual void update();

    virtual void draw();

    float getShift() const;

    float getVel() const;

    void setVel(float v = -500);

    float getDistance() const {
        return distance / 100;
    }

private:
    sf::Vector2f getSpritePos(std::list<sf::Sprite>::iterator &it);

    sf::Vector2f getSpritePos(long i);

    void setRandRep();

    sf::Vector2f spriteSize;
    float distance;
    float pos = 0;
    float shift = 0;
    float vel;
    sf::Clock levelClock;
    std::list<sf::Sprite> sprites;
    int countSprites;
    ModelGame &modelGame;

    const float levelDuration = 10;
    const float levelUpAcc = -20;
    const float levelUpTime = 5;

    int nBg;
    const int maxRep;
    const int minRep;
    Image active;
    int countRep;
    int randRep;
};


#endif //CATULA_BACKGROUND_H

//
// Created by Lorenzo Nuti and Paolo Valcepina on 17/03/17.
//

#ifndef CATULA_BACKGROUND_H
#define CATULA_BACKGROUND_H

#include <list>
#include <SFML/Graphics.hpp>

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

private:

    sf::Vector2f getSpritePos(std::list<sf::Sprite>::iterator &it);

    sf::Vector2f getSpritePos(long i);

    const float levelDuration = 10;
    const float levelUpAcc = -100;
    const float levelUpTime = 5;

    sf::Vector2f spriteSize;
    float vel;
    float pos = 0;
    float shift = 0;
    sf::Clock levelClock;
    std::list<sf::Sprite> sprites;
    int countSprites;
    ModelGame &modelGame;
};

#endif //CATULA_BACKGROUND_H
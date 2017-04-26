//
// Created by Lorenzo Nuti and Paolo Valcepina on 17/03/17.
//

#ifndef CATULA_BACKGROUND_H
#define CATULA_BACKGROUND_H

#include <list>
#include <SFML/Graphics.hpp>

#include "Drawable.h"
#include "Window.h"

class Background : public Drawable {
public:
    static Background *getInstance();

    virtual void update(const sf::Time &elapsed) override;

    virtual void draw(Window &window) override;

    float getShift() const;

private:
    Background();

    sf::Vector2f getSpritePos(std::list<sf::Sprite>::iterator &it);

    sf::Vector2f getSpritePos(long i);

    static Background *instance;

    const float levelDuration = 10;
    const float levelUpAcc = -1;
    const float levelUpTime = 5;

    sf::Vector2f spriteSize;
    float v = -5;
    float pos = 0;
    float shift = 0;
    sf::Clock levelClock;
    sf::Texture texture;
    std::list<sf::Sprite> sprites;
};

#endif //CATULA_BACKGROUND_H
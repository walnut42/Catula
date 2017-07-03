//
// Created by Lorenzo Nuti and Paolo Valcepina on 17/03/17.
//

#include "Background.h"


Background::Background(ModelGame &modelGame) : spriteSize(1251, 1000), modelGame(modelGame), countSprites(0),
                                               distance{0} {
    setVel();
}

void Background::update() {
    // update level time
    float levelTime = levelClock.getElapsedTime().asSeconds();
    if (levelTime > levelDuration) {
        if (levelTime > levelDuration + levelUpTime) {
            levelClock.restart();
        } else
            vel += levelUpAcc * Window::getInstance()->getElapsed();
    }

    // update position
    shift = vel * Window::getInstance()->getElapsed();
    pos += shift;
    distance -= shift;

    // If first sprite is out on the left side, the loop removes it.
    while (!sprites.empty() && getSpritePos(0).x + spriteSize.x < 0) {
        sprites.erase(sprites.begin());
        pos += spriteSize.x;
    }

    // If last sprite is in on the right, the loop adds a new one.
    while (sprites.empty() || getSpritePos(sprites.size() - 1).x + spriteSize.x < Window::getWidth()) {
        sf::Sprite sprite;
        if (countSprites < 10)
            Images::setSprite(sprite, Image::CemeteryBk);
        else
            Images::setSprite(sprite, Image::SunBk);
        countSprites++;
        if (countSprites > 20)
            countSprites = 0;

        sprites.push_back(sprite);
    }
}

void Background::draw() {
    for (auto it = sprites.begin(), end = sprites.end(); it != end; ++it) {
        Window::getInstance()->drawSprite(*it, getSpritePos(it), sf::Vector2f(vel, 0));
    }
}

sf::Vector2f Background::getSpritePos(std::list<sf::Sprite>::iterator &it) {
    return getSpritePos(std::distance(sprites.begin(), it));
}

sf::Vector2f Background::getSpritePos(long i) {
    return sf::Vector2f(pos + spriteSize.x * i, 0);
}

float Background::getShift() const {
    return shift;
}

float Background::getVel() const {
    return vel;
}

void Background::setVel(float v) {
    Background::vel = v;
}

//
// Created by Lorenzo Nuti and Paolo Valcepina on 17/03/17.
//

#include "Background.h"

Background::Background(ModelGame &modelGame) : spriteSize(1251, 1000), modelGame(modelGame), countSprites(0),
                                               distance{0}, countRep{0} {
    randRep = rand() % 3 + 1;

    // Get Image index.
    nBg = Images::getNumberBg();
    int randSel = 4 * (rand() % nBg) + 1;

    sf::Sprite sprite;
    active = Image(randSel);
    Images::setSprite(sprite, active);
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
        if (countRep < randRep) {
            Images::setSprite(sprite, active);
            countRep++;
        } else {

            // get the random value excluding the active image
            int next = (((rand() % (nBg - 1) + 1) + ((static_cast<int>(active) - 1) / (nBg + 1))) % nBg) * 4 + 1;

            // get the transition bg index
            int trans = nBg * ((static_cast<int>(active) - 1) / (nBg + 1) + 1) + (next - 1) / (nBg + 1) + 1 - nBg;

            Images::setSprite(sprite, Image(trans));

            active = Image(next);

            randRep = rand() % 3 + 1;
            countRep = 0;
        }
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

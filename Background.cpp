//
// Created by Lorenzo Nuti and Paolo Valcepina on 17/03/17.
//

#include "Background.h"

Background::Background(ModelGame &modelGame) : spriteSize{1251, 1000}, modelGame{modelGame}, countSprites{0},
                                               distance{0}, pos{0}, shift{0}, countRep{0}, maxRep{20}, minRep{10} {
    setRandRep();

    // Get Image index.
    nBg = Images::getNumberBg();
    int randSel = (nBg + 1) * (std::rand() % nBg) + 1;

    sf::Sprite sprite;
    active = Image(randSel);
    Images::setSprite(sprite, active);
    setVel();
}

void Background::update() {

    // Update level time.
    float levelTime = levelClock.getElapsedTime().asSeconds();
    if (levelTime > levelDuration) {
        if (levelTime > levelDuration + levelUpTime) {
            levelClock.restart();
        } else
            vel += levelUpAcc * Window::getInstance()->getElapsed();
    }

    // Update position.
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

            // Get the random value from 1 to nBg.
            int nextRand = std::rand() % (nBg - 1) + 1;

            // Get the bg index from 0 to (nBg - 1).
            int bgIndex = (static_cast<int>(active) - 1) / (nBg + 1);

            // Get the random value excluding the active image.
            int next = ((nextRand + bgIndex) % nBg) * (nBg + 1) + 1;

            // Get the nextBg index from 0 to (nBg - 1).
            int nextBgIndex = (next - 1) / (nBg + 1);

            // Get the transition bg index.
            int trans = nBg * (bgIndex + 1) + nextBgIndex + 1 - nBg;

            Images::setSprite(sprite, Image(trans));

            active = Image(next);

            setRandRep();
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

float Background::getShift() const {
    return shift;
}

float Background::getVel() const {
    return vel;
}

void Background::setVel(float v) {
    Background::vel = v;
}

sf::Vector2f Background::getSpritePos(std::list<sf::Sprite>::iterator &it) {
    return getSpritePos(std::distance(sprites.begin(), it));
}

sf::Vector2f Background::getSpritePos(long i) {
    return sf::Vector2f(pos + spriteSize.x * i, 0);
}

void Background::setRandRep() {
    Background::randRep = std::rand() % maxRep + minRep;;
}

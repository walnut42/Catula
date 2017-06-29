//
// Created by Lorenzo Nuti and Paolo Valcepina on 17/03/17.
//

#include "Background.h"

Background *Background::instance = nullptr;

Background::Background() : spriteSize(2802, 1000) {
    if (texture.loadFromFile("../Resources/background.png"))
        texture.setSmooth(true);
}

void Background::update() {
    // update level time
    float levelTime = levelClock.getElapsedTime().asSeconds();
    if (levelTime > levelDuration) {
        if (levelTime > levelDuration + levelUpTime) {
            levelClock.restart();
        } else
            v += levelUpAcc * Window::getInstance()->getElapsed();
    }

    // update position
    shift = v * Window::getInstance()->getElapsed();
    pos += shift;

    // If first sprite is out on the left side, the loop removes it.
    while (!sprites.empty() && getSpritePos(0).x + spriteSize.x < 0) {
        sprites.erase(sprites.begin());
        pos += spriteSize.x;
    }

    // If last sprite is in on the right, the loop adds a new one.
    while (sprites.empty() || getSpritePos(sprites.size() - 1).x + spriteSize.x < Window::getWidth()) {
        sf::Sprite sprite(texture);
        //sf::Vector2u oldSize = sprite.getTexture()->getSize();
        //sprite.setScale(spriteSize.x / oldSize.x, spriteSize.y / oldSize.y);
        sprites.push_back(sprite);
    }
}

void Background::draw() {
    for (auto it = sprites.begin(), end = sprites.end(); it != end; ++it) {
        Window::getInstance()->drawSprite(*it, getSpritePos(it), sf::Vector2f(v, 0));
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
    return v;
}

Background *Background::getInstance() {
    if (instance == nullptr) {
        instance = new Background;
    }
    return instance;
}

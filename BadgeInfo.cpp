//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#include "BadgeInfo.h"
#include "BadgesManager.h"


BadgeInfo::BadgeInfo(const std::string &className) : locked{true}, progress{0},
                                                     ptr{nullptr}, className{className} {
}

BadgeInfo::~BadgeInfo() {
    destroyBadge();
}

void BadgeInfo::destroyBadge() {
    if (ptr != nullptr) {
        updateBadge();
        delete ptr;
        ptr = nullptr;
    }
}

void BadgeInfo::loadBadge(std::fstream &stream) {
    readBinary(stream, locked);
    readBinary(stream, progress);
}

void BadgeInfo::saveBadge(std::fstream &stream) {
    writeBinary(stream, locked);
    writeBinary(stream, progress);
}

void BadgeInfo::updateBadge() {
    if (ptr != nullptr) {
        locked = ptr->isLocked();
        progress = ptr->getProgress();
    }
}

void BadgeInfo::setTexture(sf::Texture &t) {
    texture = t;
    Images::setSprite(bar, Image::Bar);
    Images::setSprite(barEmpty, Image::BarEmpty);
}

void BadgeInfo::drawBadge(Window *window, float x, float y) {
    updateBadge();
    if (locked)
        Images::setSprite(sprite, Image::BadgeLocked);
    else
        sprite.setTexture(texture);

    int size = BadgesManager::getInstance()->getBadgeSize();
    sprite.setOrigin(sprite.getGlobalBounds().width / 2.0f, 0);
    window->drawSprite(sprite, sf::Vector2f(x, y));

    barEmpty.setOrigin(barEmpty.getGlobalBounds().width / 2.0f, 0);
    window->drawSprite(barEmpty, sf::Vector2f(x, y + size + 5));

    bar.setTextureRect(
            sf::IntRect(0, 0, static_cast<int>(getProgress() / 100 * size), 9));
    window->drawSprite(bar,
                       sf::Vector2f(x - barEmpty.getGlobalBounds().width / 2.0f, y + size + 5));
}

const std::string &BadgeInfo::getClassName() const {
    return className;
}

float BadgeInfo::getProgress() {
    return (!locked || progress > 100) ? 100 : progress;
}

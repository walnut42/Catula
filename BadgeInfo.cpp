//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#include "BadgeInfo.h"


BadgeInfo::BadgeInfo(Badge *(*f)(MainCharacter *, float)) : creator{f}, locked{true}, progress{0},
                                                            ptr{nullptr} {
}

BadgeInfo::~BadgeInfo() {
    destroyBadge();
}

void BadgeInfo::createBadge(MainCharacter *mC) {
    if (locked)
        ptr = creator(mC, progress);
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
    window->drawSprite(sprite, sf::Vector2f(x, y));
    window->drawSprite(barEmpty, sf::Vector2f(x, y + 155));
    bar.setTextureRect(sf::IntRect(0, 0, progress / 100 * 150, 9));
    window->drawSprite(bar, sf::Vector2f(x, y + 155));

}

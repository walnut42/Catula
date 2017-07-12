//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#include "BadgeInfo.h"

#include <iomanip>

#include "BadgesManager.h"

BadgeInfo::BadgeInfo(const std::string &className, const std::string &description) : locked{true}, progress{0},
                                                                                     ptr{nullptr}, className{className},
                                                                                     description{description} {
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

bool BadgeInfo::updateBadge() {
    if (ptr != nullptr) {
        progress = ptr->getProgress();
        if (locked && !ptr->isLocked()) {
            locked = ptr->isLocked();
            return true;
        }
    }
    return false;
}

void BadgeInfo::drawBadge(Window *window, float x, float y, int padding, int barHeight) {
    if (locked)
        Images::setSprite(sprite, Image::BadgeLocked);
    else
        sprite.setTexture(texture);

    int size = BadgesManager::getInstance()->getBadgeSize();
    sprite.setScale(1, 1);
    sprite.setOrigin(0, 0);
    window->drawSprite(sprite, sf::Vector2f(x, y));

    barEmpty.setOrigin(0, 0);
    window->drawSprite(barEmpty, sf::Vector2f(x, y + size + padding));

    bar.setTextureRect(
            sf::IntRect(0, 0, static_cast<int>(progress / 100 * size), barHeight));
    window->drawSprite(bar,
                       sf::Vector2f(x, y + size + padding));

}

void BadgeInfo::drawNotify(Window *window, float x, float y) {
    sprite.setTexture(texture);
    sprite.setScale(0.5f, 0.5f);
    sprite.setOrigin(0, 0);
    window->drawSprite(sprite, sf::Vector2f(x, y));
}

void BadgeInfo::setTexture(sf::Texture &t) {
    texture = t;
    Images::setSprite(bar, Image::Bar);
    Images::setSprite(barEmpty, Image::BarEmpty);
}

const std::string &BadgeInfo::getClassName() const {
    return className;
}

const std::string BadgeInfo::getDescription() const {
    if (locked) {
        std::stringstream stream;
        stream << std::fixed << std::setprecision(0) << progress;
        return "Locked!! Progress: " + stream.str() + "%";
    } else
        return description;
}

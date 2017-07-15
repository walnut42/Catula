//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/07/17.
//

#include "Badge.h"

#include "Tools.h"
#include "Window.h"
#include "BadgesManager.h"


Badge::Badge(const std::string &className, const std::string &name, const std::string &description,
             float goal, bool memorize) : locked{true}, points{0}, goalPoints{goal}, memorize{memorize},
                                          mainCharacter{nullptr},
                                          className{className}, name{name}, description{description} {
}


Badge::~Badge() {
}


void Badge::load(std::fstream &stream) {
    readBinary(stream, locked);
    readBinary(stream, points);
    if (!memorize)
        points = 0;
}

void Badge::save(std::fstream &stream) {
    writeBinary(stream, locked);
    writeBinary(stream, points);
}

void Badge::update() {
    if (points >= goalPoints)
        unlock();
}


bool Badge::updateLockedStatus() {
    if (locked && points >= goalPoints) {
        locked = false;
        return true;
    }
    return false;
}

bool Badge::isLocked() const {
    return locked;
}

float Badge::getProgress() const {
    if (!locked)
        return 100;
    else if (memorize)
        return points * 100 / goalPoints;
    else
        return 0;
}

void Badge::unlock() {
    //locked = false;
    detach();
}


void Badge::drawBadge(Window *window, float x, float y, int padding, int barHeight) {
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

    bar.setTextureRect(sf::IntRect(0, 0, static_cast<int>(getProgress() / 100 * size), barHeight));
    window->drawSprite(bar, sf::Vector2f(x, y + size + padding));

}

void Badge::drawNotify(Window *window, float x, float y) {
    sprite.setTexture(texture);
    sprite.setScale(0.5f, 0.5f);
    sprite.setOrigin(0, 0);
    window->drawSprite(sprite, sf::Vector2f(x, y));
}

void Badge::setTexture(const std::string &path) {
    texture.loadFromFile(path);
    texture.setSmooth(true);
    Images::setSprite(bar, Image::Bar);
    Images::setSprite(barEmpty, Image::BarEmpty);
}

const std::string &Badge::getClassName() const {
    return className;
}


const std::string Badge::getDescription() const {
    if (locked) {
        if (memorize)
            return "Locked!! Progress: " + toString(getProgress()) + "%";
        else
            return "Locked!!";
    } else
        return description;
}


const std::string &Badge::getName() const {
    return name;
}


void Badge::addObserver(MainCharacter *mC) {
    if (locked && mainCharacter == nullptr) {
        mainCharacter = mC;
        attach();
    }
}


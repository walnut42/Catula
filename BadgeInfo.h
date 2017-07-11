//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#ifndef CATULA_BADGEINFO_H
#define CATULA_BADGEINFO_H

#include <SFML/Graphics.hpp>
#include <fstream>

#include "Badge.h"
#include "Window.h"
#include "MainCharacter.h"

template<typename T>
void readBinary(std::fstream &stream, T &value) {
    stream.read(reinterpret_cast<char *>(&value), sizeof value);
}


template<typename T>
void writeBinary(std::fstream &stream, T &value) {
    stream.write(reinterpret_cast<char *>(&value), sizeof value);
}


class BadgeInfo {
public:
    BadgeInfo(const std::string &className);

    ~BadgeInfo();

    virtual void createBadge(MainCharacter *mC)=0;

    void destroyBadge();

    void setTexture(sf::Texture &t);

    void loadBadge(std::fstream &stream);

    void saveBadge(std::fstream &stream);

    void drawBadge(Window *window, float x, float y);

    void drawNotify(Window *window, float x, float y);

    const std::string &getClassName() const;

    bool updateBadge();

protected:
    bool locked;
    float progress;
    Badge *ptr;

    sf::Texture texture;
    sf::Sprite sprite;
    sf::Sprite bar;
    sf::Sprite barEmpty;
    const std::string className;
};


template<typename T>
class BadgeInfoT : public BadgeInfo {
public:
    BadgeInfoT(const std::string &className) : BadgeInfo{className} {

    }

    virtual void createBadge(MainCharacter *mC) {
        if (locked)
            ptr = new T(mC, progress);
    }
};

#endif //CATULA_BADGEINFO_H

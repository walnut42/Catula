//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#ifndef CATULA_BADGEINFO_H
#define CATULA_BADGEINFO_H

#include <SFML/Graphics.hpp>
#include <fstream>

#include "Badge.h"
#include "MainCharacter.h"


template<typename T>
Badge *createInstance(MainCharacter *mC, float progress) {
    return new T(mC, progress);
}

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
    BadgeInfo(Badge *(*f)(MainCharacter *mC, float progress));

    ~BadgeInfo();

    void createBadge(MainCharacter *mC);

    void destroyBadge();

    void loadBadge(std::fstream &stream);

    void saveBadge(std::fstream &stream);

    void updateBadge();

private:
    Badge *(*creator)(MainCharacter *mC, float progress);

    bool locked;
    float progress;
    Badge *ptr;
};


#endif //CATULA_BADGEINFO_H

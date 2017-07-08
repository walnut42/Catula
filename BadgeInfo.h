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
Badge *createInstance(MainCharacter *mC, bool locked, float progress) {
    return new T(mC, locked, progress);
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
    BadgeInfo(Badge *(*f)(MainCharacter *mC, bool locked, float progress)) : creator{f}, locked{true}, progress{0},
                                                                             ptr{nullptr} {
    }

    ~BadgeInfo() {
        destroyBadge();
    }

    void createBadge(MainCharacter *mC) {
        if (locked)
            ptr = creator(mC, locked, progress);
    }

    void destroyBadge() {
        if (ptr != nullptr) {
            updateBadge();
            delete ptr;
            ptr = nullptr;
        }
    }

    void loadBadge(std::fstream &stream) {
        readBinary(stream, locked);
        readBinary(stream, progress);
    }

    void saveBadge(std::fstream &stream) {
        writeBinary(stream, locked);
        writeBinary(stream, progress);
    }

    void updateBadge() {
        if (ptr != nullptr) {
            locked = ptr->isLocked();
            progress = ptr->getProgress();
        }
    }

private:
    Badge *(*creator)(MainCharacter *mC, bool locked, float progress);

    bool locked;
    float progress;
    Badge *ptr;
};


#endif //CATULA_BADGEINFO_H

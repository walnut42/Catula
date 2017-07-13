//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/07/17.
//

#include "Badge.h"

Badge::Badge(MainCharacter *mC, float goalPoints, bool memorize, float p) : locked{true}, goalPoints{goalPoints},
                                                                            mainCharacter{mC}, memorize{memorize} {
    if (memorize)
        points = p * goalPoints / 100;
    else
        points = 0;
}

Badge::~Badge() {

}

void Badge::update() {
    if (points >= goalPoints)
        unlock();
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
    locked = false;
    detach();
}

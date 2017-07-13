//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/07/17.
//

#include "Badge.h"

Badge::Badge(MainCharacter *mC, float goalPoints, float p) : locked{true}, goalPoints{goalPoints},
                                                             mainCharacter{mC}, progress{true} {
    if (p == -1) {
        progress = false;
        p = 0;
    }
    points = p * goalPoints / 100;
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
    else if (progress)
        return points * 100 / goalPoints;
    else
        return 0;
}

void Badge::unlock() {
    locked = false;
    detach();
}

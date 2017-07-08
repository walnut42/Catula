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

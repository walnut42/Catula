//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#include "BadgeFly.h"

// Fly on the top of the screen for goalPoints distance (progress).

BadgeFly::BadgeFly(MainCharacter *mC, float goal, float p) : Badge{mC, goal, p}, top{false}, initDistance{0} {
    attach();
}

BadgeFly::~BadgeFly() {
    detach();
}

void BadgeFly::attach() {
    mainCharacter->subscribe(Subscription::Position, this);
}

void BadgeFly::detach() {
    if (mainCharacter != nullptr) {
        mainCharacter->unsubscribe(Subscription::Position, this);
        mainCharacter = nullptr;
    }
}

void BadgeFly::update() {
    if (mainCharacter->getPos().y <= 0) {
        if (!top) {
            initDistance = mainCharacter->getDistance();
            top = true;
        } else {
            float d = mainCharacter->getDistance();
            points += d - initDistance;
            initDistance = d;
        }
    } else if (top)
        top = false;

    Badge::update();
}

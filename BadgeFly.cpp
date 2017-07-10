//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#include "BadgeFly.h"

// Fly on the top of the screen for goalPoints milliseconds (progress).

BadgeFly::BadgeFly(MainCharacter *mC, float p) : Badge{mC, 10000, p} {
    top = false;
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
            time = clock.restart();
            top = true;
        } else if (mainCharacter->getLives() < 0) {
            time = clock.restart();
            points += time.asMilliseconds();
        }
    } else {
        if (top) {
            time = clock.restart();
            points += time.asMilliseconds();
            top = false;
        }
    }
    Badge::update();
}

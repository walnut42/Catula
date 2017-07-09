//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#include "BadgeFly.h"

BadgeFly::BadgeFly(MainCharacter *mC, float p) : Badge{mC, p} {
    points = progress * goalPoints / 100;
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
    if (points >= 10000) {
        locked = false;
        progress = 100;
        detach();
    }
    progress = points * 100 / goalPoints;
}

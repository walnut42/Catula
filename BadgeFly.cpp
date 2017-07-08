//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#include "BadgeFly.h"

BadgeFly::BadgeFly(MainCharacter *mC, float p) : Badge{mC, p} {
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
            progress += time.asMilliseconds();
        }
    } else {
        if (top) {
            time = clock.restart();
            progress += time.asMilliseconds();
            top = false;
        }
    }
    if (progress > 0) {
        locked = false;
        detach();
    }
}

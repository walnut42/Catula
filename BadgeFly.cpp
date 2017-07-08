//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#include "BadgeFly.h"

BadgeFly::BadgeFly(MainCharacter *mC, bool l, float p) {
    mainCharacter = mC;
    locked = l;
    progress = p;
    top = false;
    if (l)
        attach();
}

BadgeFly::~BadgeFly() {
    detach();
}

void BadgeFly::attach() {
    mainCharacter->subscribe(Subscription::Position, this);
}

void BadgeFly::detach() {
    if (mainCharacter != nullptr)
        mainCharacter->unsubscribe(Subscription::Position, this);
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
            std::cout << progress << std::endl;
        }
    }
    if (progress > 10000) {
        locked = false;

        // TODO: save
    }
}

//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#include "BadgeFly.h"

// Fly on the top of the screen for goal distance (progress).

BadgeFly::BadgeFly(const std::string &className, const std::string &name, const std::string &description, float goal,
                   bool memorize) : Badge{className, name, description, goal, memorize}, top{false}, initDistance{0} {
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

//
// Created by Lorenzo Nuti and Paolo Valcepina on 11/07/17.
//

#include "BadgeDistance.h"


// Get 100 distance points (progress).

BadgeDistance::BadgeDistance(MainCharacter *mC, float p) : Badge{mC, 100, p} {
    previousDistance = mainCharacter->getDistance();
    attach();
}

BadgeDistance::~BadgeDistance() {
    detach();
}

void BadgeDistance::attach() {
    mainCharacter->subscribe(Subscription::Position, this);
}

void BadgeDistance::detach() {
    if (mainCharacter != nullptr) {
        mainCharacter->unsubscribe(Subscription::Position, this);
        mainCharacter = nullptr;
    }

}

void BadgeDistance::update() {
    distance = mainCharacter->getDistance();
    points += distance - previousDistance;
    previousDistance = distance;
    Badge::update();
}

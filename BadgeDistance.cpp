//
// Created by Lorenzo Nuti and Paolo Valcepina on 11/07/17.
//

#include "BadgeDistance.h"


// Get goal distance points (progress).

BadgeDistance::BadgeDistance(const std::string &className, const std::string &name, const std::string &description, float goal,
                             bool memorize) : Badge{className, name, description, goal, memorize},previousDistance{0},
                                                                               distance{0} {
}

void BadgeDistance::attach(MainCharacter *mC) {
    previousDistance = mC->getDistance();
    subscribe(mC, Subscription::Position);
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

//
// Created by Lorenzo Nuti and Paolo Valcepina on 11/07/17.
//

#include "BadgeSpeed.h"

// Get maxSpeed = goal

BadgeSpeed::BadgeSpeed(const std::string &className, const std::string &name, const std::string &description, float goal,
                       bool memorize) : Badge{className, name, description, goal, memorize}, speed{0} {
}

void BadgeSpeed::attach(MainCharacter *mC) {
    subscribe(mC, Subscription::Position);
}

void BadgeSpeed::detach() {
    if (mainCharacter != nullptr) {
        mainCharacter->unsubscribe(Subscription::Position, this);
        mainCharacter = nullptr;
    }
}

void BadgeSpeed::update() {
    speed = mainCharacter->getVelX();
    if (points < speed)
        points = speed;
    Badge::update();
}

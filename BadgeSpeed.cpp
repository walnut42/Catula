//
// Created by Lorenzo Nuti and Paolo Valcepina on 11/07/17.
//

#include "BadgeSpeed.h"

// Get maxSpeed = goalPoints

BadgeSpeed::BadgeSpeed(MainCharacter *mC, float goal, float p) : Badge{mC, goal}, speed{0} {
    attach();
}

BadgeSpeed::~BadgeSpeed() {
    detach();
}

void BadgeSpeed::attach() {
    mainCharacter->subscribe(Subscription::Position, this);
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

//
// Created by Lorenzo Nuti and Paolo Valcepina on 11/07/17.
//

#include "BadgeSpeed.h"

// Get maxSpeed = 1000

BadgeSpeed::BadgeSpeed(MainCharacter *mC, float p) : Badge{mC, 600, p} {
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
    speed = -mainCharacter->getVelX();
    if (points < speed)
        points = speed;
    Badge::update();
}

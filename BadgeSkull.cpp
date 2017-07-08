//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#include "BadgeSkull.h"

BadgeSkull::BadgeSkull(MainCharacter *mC, float p) : Badge{mC, p} {
    attach();
}

BadgeSkull::~BadgeSkull() {
    detach();
}

void BadgeSkull::attach() {
    mainCharacter->subscribe(Subscription::Score, this);
}

void BadgeSkull::detach() {
    if (mainCharacter != nullptr) {
        mainCharacter->unsubscribe(Subscription::Score, this);
        mainCharacter = nullptr;
    }

}

void BadgeSkull::update() {
    progress += static_cast<int>(Score::Skull);
    if (progress > 0) {
        locked = false;
        detach();
    }
}

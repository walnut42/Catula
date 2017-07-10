//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#include "BadgeSkull.h"

// Get goalPoints skulls (progress).

BadgeSkull::BadgeSkull(MainCharacter *mC, float p) : Badge{mC, 5, p} {
    previousScore = mainCharacter->getScore();
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
    int score = mainCharacter->getScore();
    if (score == previousScore + static_cast<int>(Score::Skull))
        points++;
    previousScore = score;
    Badge::update();
}

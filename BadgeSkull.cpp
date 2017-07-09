//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#include "BadgeSkull.h"

BadgeSkull::BadgeSkull(MainCharacter *mC, float p) : Badge{mC, p} {
    previousScore = mainCharacter->getScore();
    points = progress * goalPoints / 100;
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
    if (score == previousScore + static_cast<int>(Score::Skull)) {
        points++;
        if (points >= goalPoints) {
            locked = false;
            progress = 100;
            detach();
        } else
            progress = points * 100 / goalPoints;
    }
    previousScore = score;
}

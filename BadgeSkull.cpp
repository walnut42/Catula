//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#include "BadgeSkull.h"

// Get goal skulls (progress).

BadgeSkull::BadgeSkull(const std::string &className, const std::string &name, const std::string &description,
                       float goal, bool memorize) : Badge{className, name, description, goal, memorize},
                                                    previousScore{0}, score{0} {

}


void BadgeSkull::attach(MainCharacter *mC) {
    previousScore = mC->getScore();
    subscribe(mC, Subscription::Score);
}

void BadgeSkull::detach() {
    if (mainCharacter != nullptr) {
        mainCharacter->unsubscribe(Subscription::Score, this);
        mainCharacter = nullptr;
    }

}

void BadgeSkull::update() {
    score = mainCharacter->getScore();
    if (score == previousScore + static_cast<int>(Score::Skull))
        points++;
    previousScore = score;
    Badge::update();
}

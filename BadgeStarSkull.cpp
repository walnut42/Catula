//
// Created by Lorenzo Nuti and Paolo Valcepina on 11/07/17.
//

#include "BadgeStarSkull.h"

// Get goal stars and skulls (progress).

BadgeStarSkull::BadgeStarSkull(const std::string &className, const std::string &name, const std::string &description,
                               float goal, bool memorize) : Badge{className, name, description, goal, memorize},
                                                            previousScore{0} {
}

void BadgeStarSkull::attach(MainCharacter *mC) {
    previousScore = mC->getScore();
    subscribe(mC, Subscription::Score);
}

void BadgeStarSkull::detach() {
    if (mainCharacter != nullptr) {
        mainCharacter->unsubscribe(Subscription::Score, this);
        mainCharacter = nullptr;
    }

}

void BadgeStarSkull::update() {
    int score = mainCharacter->getScore();
    if (score == previousScore + static_cast<int>(Score::Skull) ||
        score == previousScore + static_cast<int>(Score::Star))
        points++;
    previousScore = score;
    Badge::update();
}

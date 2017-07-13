//
// Created by Lorenzo Nuti and Paolo Valcepina on 11/07/17.
//

#include "BadgeStarSkull.h"

// Get goal stars and skulls (progress).

BadgeStarSkull::BadgeStarSkull(MainCharacter *mC, float goal, bool m, float p) : Badge{mC, goal, m, p} {
    previousScore = mainCharacter->getScore();
    attach();
}

BadgeStarSkull::~BadgeStarSkull() {
    detach();
}

void BadgeStarSkull::attach() {
    mainCharacter->subscribe(Subscription::Score, this);
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

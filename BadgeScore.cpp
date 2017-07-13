//
// Created by Lorenzo Nuti and Paolo Valcepina on 11/07/17.
//

#include "BadgeScore.h"

// Get goal points (progress).

BadgeScore::BadgeScore(MainCharacter *mC, float goal, bool m, float p) : Badge{mC, goal, m, p},
                                                                         previousScore{mainCharacter->getScore()},
                                                                         score{0} {
    attach();
}

BadgeScore::~BadgeScore() {
    detach();
}

void BadgeScore::attach() {
    mainCharacter->subscribe(Subscription::Score, this);
}

void BadgeScore::detach() {
    if (mainCharacter != nullptr) {
        mainCharacter->unsubscribe(Subscription::Score, this);
        mainCharacter = nullptr;
    }
}

void BadgeScore::update() {
    score = mainCharacter->getScore();
    points += score - previousScore;
    previousScore = score;
    Badge::update();
}

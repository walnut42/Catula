//
// Created by Lorenzo Nuti and Paolo Valcepina on 11/07/17.
//

#include "BadgeScore.h"

// Get 20 points (progress).

BadgeScore::BadgeScore(MainCharacter *mC, float p) : Badge{mC, 20, p}, previousScore{mainCharacter->getScore()} {
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

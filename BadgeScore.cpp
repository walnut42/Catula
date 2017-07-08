//
// Created by Lorenzo Nuti and Paolo Valcepina on 07/07/17.
//

#include "BadgeScore.h"

BadgeScore::BadgeScore(MainCharacter *mC, float p) : Badge{mC, p}, count{0}, previousScore{0}, previousLives{0} {
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
    mainCharacter->getScore() > previousScore || mainCharacter->getLives() >= previousLives ? count++ : count = 0;
    previousScore = mainCharacter->getScore();
    previousLives = mainCharacter->getLives();

    if (count > 2) {
        locked = false;
        detach();
    }
}

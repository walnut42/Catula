//
// Created by Lorenzo Nuti and Paolo Valcepina on 07/07/17.
//

#include "BadgeScore.h"

// Get goalPoints positive objects in a row.

BadgeScore::BadgeScore(MainCharacter *mC, float p) : Badge{mC, 10}, count{0} {
    previousScore = mainCharacter->getScore();
    previousLives = mainCharacter->getLives();
    attach();
}

BadgeScore::~BadgeScore() {
    detach();
}

void BadgeScore::attach() {
    mainCharacter->subscribe(Subscription::Score, this);
    mainCharacter->subscribe(Subscription::Life, this);
}

void BadgeScore::detach() {
    if (mainCharacter != nullptr) {
        mainCharacter->unsubscribe(Subscription::Score, this);
        mainCharacter->unsubscribe(Subscription::Life, this);
        mainCharacter = nullptr;
    }
}

void BadgeScore::update() {
    mainCharacter->getScore() > previousScore || mainCharacter->getLives() >= previousLives ? count++ : count = 0;
    previousScore = mainCharacter->getScore();
    previousLives = mainCharacter->getLives();
    Badge::update();
}

//
// Created by Lorenzo Nuti and Paolo Valcepina on 07/07/17.
//

#include "BadgeScore.h"

BadgeScore::BadgeScore(MainCharacter *mC, bool l, float p) {
    std::cout << "BadgeScore" << std::endl;
    mainCharacter = mC;
    progress = 0;
    count = 0;
    previousScore = 0;
    attach();
}

BadgeScore::~BadgeScore() {
    detach();
}

void BadgeScore::attach() {
    std::cout << "BadgeScore::attach" << std::endl;
    mainCharacter->subscribe(Subscription::Score, this);
}

void BadgeScore::detach() {
    std::cout << "BadgeScore::detach" << std::endl;
    if (mainCharacter != nullptr) {
        mainCharacter->unsubscribe(Subscription::Score, this);
        mainCharacter = nullptr;
    }
}

void BadgeScore::update() {
    std::cout << "BadgeScore::update" << std::endl;
    mainCharacter->getScore() > previousScore || mainCharacter->getLives() >= previousLives ? count++ : count = 0;
    previousScore = mainCharacter->getScore();
    previousLives = mainCharacter->getLives();

    if (count > 2) {
        locked = false;
        detach();
    }
}

//
// Created by Lorenzo Nuti and Paolo Valcepina on 11/07/17.
//

#include "BadgeScore.h"

// Get goal points (progress).

BadgeScore::BadgeScore(const std::string &className, const std::string &name, const std::string &description,
                       float goal, bool memorize) : Badge{className, name, description, goal, memorize},
                                                    previousScore{0}, score{0} {
}


void BadgeScore::attach() {
    previousScore = mainCharacter->getScore();
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

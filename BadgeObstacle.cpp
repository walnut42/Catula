//
// Created by Lorenzo Nuti and Paolo Valcepina on 07/07/17.
//

#include "BadgeObstacle.h"

// Get goal positive objects in a row.

BadgeObstacle::BadgeObstacle(const std::string &className, const std::string &name, const std::string &description,
                             float goal, bool memorize) : Badge{className, name, description, goal, memorize},
                                                          previousScore{0}, previousLives{0} {
}

void BadgeObstacle::attach(MainCharacter *mC) {
    previousScore = mC->getScore();
    previousLives = mC->getLives();
    subscribe(mC, Subscription::Score);
    subscribe(mC, Subscription::Life);
}

void BadgeObstacle::detach() {
    if (mainCharacter != nullptr) {
        mainCharacter->unsubscribe(Subscription::Score, this);
        mainCharacter->unsubscribe(Subscription::Life, this);
        mainCharacter = nullptr;
    }
}

void BadgeObstacle::update() {
    mainCharacter->getScore() > previousScore || mainCharacter->getLives() >= previousLives ? points++ : points = 0;
    previousScore = mainCharacter->getScore();
    previousLives = mainCharacter->getLives();
    Badge::update();
}

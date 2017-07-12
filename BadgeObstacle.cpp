//
// Created by Lorenzo Nuti and Paolo Valcepina on 07/07/17.
//

#include "BadgeObstacle.h"

// Get goalPoints positive objects in a row.

BadgeObstacle::BadgeObstacle(MainCharacter *mC, float goal, float p) : Badge{mC, goal} {
    previousScore = mainCharacter->getScore();
    previousLives = mainCharacter->getLives();
    attach();
}

BadgeObstacle::~BadgeObstacle() {
    detach();
}

void BadgeObstacle::attach() {
    mainCharacter->subscribe(Subscription::Score, this);
    mainCharacter->subscribe(Subscription::Life, this);
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

//
// Created by Lorenzo Nuti and Paolo Valcepina on 07/07/17.
//

#include "BadgeObstacle.h"

// Get goal positive objects in a row.

BadgeObstacle::BadgeObstacle(const std::string &className, const std::string &name, const std::string &description,
                             float goal, bool memorize) : Badge{className, name, description, goal, memorize},
                                                          previousScore{0}, previousLives{0} {
}

void BadgeObstacle::attach() {
    previousScore = mainCharacter->getScore();
    previousLives = mainCharacter->getLives();
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
    int score = mainCharacter->getScore();
    int lives = mainCharacter->getLives();
    if (score >= previousScore && lives >= previousLives && (score > previousScore || lives > previousLives))
        points++;
    else
        points = 0;
    previousScore = score;
    previousLives = lives;
    Badge::update();
}

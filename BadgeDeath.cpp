//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#include "BadgeDeath.h"
#include "MainCharacter.h"

// Die goal times (progress).

BadgeDeath::BadgeDeath(const std::string &className, const std::string &name, const std::string &description, float goal,
                       bool memorize) : Badge{className, name, description, goal, memorize}, previousLife{0}, life{0} {
}

void BadgeDeath::attach() {
    previousLife=mainCharacter->getLives();
    mainCharacter->subscribe(Subscription::Life, this);
}

void BadgeDeath::detach() {
    if (mainCharacter != nullptr) {
        mainCharacter->unsubscribe(Subscription::Life, this);
        mainCharacter = nullptr;
    }

}

void BadgeDeath::update() {
    life = mainCharacter->getLives();
    if (life < previousLife)
        points += previousLife - life;
    previousLife = life;
    Badge::update();
}

//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#include "BadgeDeath.h"

// Die goal times (progress).

BadgeDeath::BadgeDeath(MainCharacter *mC, float goal, float p) : Badge{mC, goal, p}, previousLife{mC->getLives()},
                                                                 life{0} {
    attach();
}

BadgeDeath::~BadgeDeath() {
    detach();
}

void BadgeDeath::attach() {
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

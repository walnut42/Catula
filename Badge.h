//
// Created by Lorenzo Nuti and Paolo Valcepina on 07/07/17.
//

#ifndef CATULA_BADGE_H
#define CATULA_BADGE_H

#include "Images.h"
#include "MainCharacter.h"

class MainCharacter;

class Badge {
public:
    explicit Badge(MainCharacter *mC, float goalPoints, float p = 0) : locked{true}, goalPoints{goalPoints},
                                                                       mainCharacter{mC},
                                                                       points{p * goalPoints / 100} {

    }

    virtual ~Badge() {}

    virtual void update() {
        if (points >= goalPoints)
            unlock();
    }

    bool isLocked() const {
        return locked;
    }

    float getProgress() const {
        return points * 100 / goalPoints;
    }

protected:
    virtual void attach()=0;

    virtual void detach()=0;

    void unlock() {
        locked = false;
        points = goalPoints;
        detach();
    }

    bool locked;
    float goalPoints;
    float points;
    MainCharacter *mainCharacter;
};


#endif //CATULA_BADGE_H

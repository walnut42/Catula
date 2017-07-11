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
    Badge(MainCharacter *mC, float goalPoints, float p = -1) : locked{true}, goalPoints{goalPoints},
                                                               mainCharacter{mC}, progress{true} {
        if (p == -1) {
            progress = false;
            p = 0;
        }
        points = p * goalPoints / 100;
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
        if (!locked)
            return 100;
        else if (progress)
            return points * 100 / goalPoints;
        else
            return 0;
    }

protected:
    virtual void attach()=0;

    virtual void detach()=0;

    void unlock() {
        detach();
        locked = false;
    }

    bool locked;
    float points;
    float goalPoints;
    MainCharacter *mainCharacter;
private:
    bool progress;
};


#endif //CATULA_BADGE_H

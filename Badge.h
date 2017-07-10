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
    explicit Badge(MainCharacter *mC, float p = 0) : locked{true}, progress{p}, mainCharacter{mC} {

    }

    virtual ~Badge() {}

    virtual void update()=0;

    bool isLocked() const {
        return locked;
    }

    float getProgress() const {
        return progress;
    }

protected:
    virtual void attach()=0;

    virtual void detach()=0;

    void unlock() {
        locked = false;
        progress = 100;
        detach();
    }
    bool locked;
    float points;
    float progress;
    MainCharacter *mainCharacter;
};


#endif //CATULA_BADGE_H

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

    bool locked;
    float progress;
    MainCharacter *mainCharacter;
};


#endif //CATULA_BADGE_H

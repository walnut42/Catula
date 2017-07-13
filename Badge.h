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
    Badge(MainCharacter *mC, float goalPoints, float p = -1);

    virtual ~Badge();

    virtual void update();

    bool isLocked() const;

    float getProgress() const;

protected:
    virtual void attach()=0;

    virtual void detach()=0;

    void unlock();

    bool locked;
    float points;
    float goalPoints;
    MainCharacter *mainCharacter;
private:
    bool progress;
};


#endif //CATULA_BADGE_H

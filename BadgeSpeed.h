//
// Created by Lorenzo Nuti and Paolo Valcepina on 11/07/17.
//

#ifndef CATULA_BADGESPEED_H
#define CATULA_BADGESPEED_H

#include "Badge.h"
#include "MainCharacter.h"
#include "ModelGame.h"


class BadgeSpeed : public Badge {
public:
    BadgeSpeed(MainCharacter *mC, float goal, bool m, float p);

    virtual ~BadgeSpeed();

    virtual void update() override;

    virtual void attach() override;

    virtual void detach() override;

private:
    float speed;
};


#endif //CATULA_BADGESPEED_H

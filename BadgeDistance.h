//
// Created by Lorenzo Nuti and Paolo Valcepina on 11/07/17.
//

#ifndef CATULA_BADGEDISTANCE_H
#define CATULA_BADGEDISTANCE_H

#include "Badge.h"
#include "MainCharacter.h"
#include "ModelGame.h"


class BadgeDistance : public Badge {
public:
    BadgeDistance(MainCharacter *mC, float goal, bool m, float p);

    virtual ~BadgeDistance();

    virtual void update() override;

    virtual void attach() override;

    virtual void detach() override;

private:
    float previousDistance;
    float distance;
};


#endif //CATULA_BADGEDISTANCE_H

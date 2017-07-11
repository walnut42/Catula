//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#ifndef CATULA_BADGESKULL_H
#define CATULA_BADGESKULL_H

#include "Badge.h"
#include "MainCharacter.h"
#include "ModelGame.h"


class BadgeSkull : public Badge {
public:
    BadgeSkull(MainCharacter *mC, float p);

    virtual ~BadgeSkull();

    virtual void update() override;

    virtual void attach() override;

    virtual void detach() override;

private:
    int previousScore;
};


#endif //CATULA_BADGESKULL_H

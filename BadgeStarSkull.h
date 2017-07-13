//
// Created by Lorenzo Nuti and Paolo Valcepina on 11/07/17.
//

#ifndef CATULA_BADGESTARSKULL_H
#define CATULA_BADGESTARSKULL_H

#include "Badge.h"
#include "MainCharacter.h"
#include "ModelGame.h"


class BadgeStarSkull : public Badge {
public:
    BadgeStarSkull(MainCharacter *mC, float goal, bool m, float p);

    virtual ~BadgeStarSkull();

    virtual void update() override;

    virtual void attach() override;

    virtual void detach() override;

private:
    int previousScore;
};


#endif //CATULA_BADGESTARSKULL_H

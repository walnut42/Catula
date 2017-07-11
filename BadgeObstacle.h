//
// Created by Lorenzo Nuti and Paolo Valcepina on 07/07/17.
//

#ifndef CATULA_BADGEOBSTACLE_H
#define CATULA_BADGEOBSTACLE_H

#include "Badge.h"
#include "ModelGame.h"
#include "MainCharacter.h"


class BadgeObstacle : public Badge {
public:
    BadgeObstacle(MainCharacter *mC, float p);

    virtual ~BadgeObstacle();

    virtual void update() override;

    virtual void attach() override;

    virtual void detach() override;

private:
    int count;
    int previousScore;
    int previousLives;
};


#endif //CATULA_BADGEOBSTACLE_H

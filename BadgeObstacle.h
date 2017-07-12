//
// Created by Lorenzo Nuti and Paolo Valcepina on 07/07/17.
//

#ifndef CATULA_BADGEOBSTACLE_H
#define CATULA_BADGEOBSTACLE_H

#include "Badge.h"
#include "MainCharacter.h"
#include "ModelGame.h"


class BadgeObstacle : public Badge {
public:
    BadgeObstacle(MainCharacter *mC, float goal, float p);

    virtual ~BadgeObstacle();

    virtual void update() override;

    virtual void attach() override;

    virtual void detach() override;

private:
    int previousScore;
    int previousLives;
};


#endif //CATULA_BADGEOBSTACLE_H

//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#ifndef CATULA_BADGEFLY_H
#define CATULA_BADGEFLY_H

#include "Badge.h"
#include "ModelGame.h"
#include "MainCharacter.h"
#include "Tools.h"


class BadgeFly : public Badge {
public:
    BadgeFly(MainCharacter *mC, float p);

    virtual ~BadgeFly();

    virtual void update() override;

    virtual void attach() override;

    virtual void detach() override;

    static BadgeData getData() {
            BadgeData data;
            data.goalPoints = 10;
            data.name = "Fly master";
            data.description = toString(data.goalPoints) + " distance points on the top";
            return data;
    }

private:
    bool top;
    float initDistance;
    sf::Clock clock;
    sf::Time time;
};


#endif //CATULA_BADGEFLY_H

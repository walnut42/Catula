//
// Created by Lorenzo Nuti and Paolo Valcepina on 11/07/17.
//

#ifndef CATULA_BADGEDISTANCE_H
#define CATULA_BADGEDISTANCE_H

#include "ModelGame.h"
#include "MainCharacter.h"
#include "Badge.h"


class BadgeDistance : public Badge {
public:
    BadgeDistance(const std::string &className, const std::string &name, const std::string &description, float goal,
                  bool memorize);

    virtual void update() override;

    virtual void detach() override;

private:
    virtual void attach() override;

    float previousDistance;
    float distance;
};


#endif //CATULA_BADGEDISTANCE_H

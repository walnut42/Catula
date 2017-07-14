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
    BadgeDistance(const std::string &className, const std::string &name, const std::string &description, float goal,
                  bool memorize);

    virtual void update() override;

    virtual void attach(MainCharacter *mC) override;

    virtual void detach() override;

private:
    float previousDistance;
    float distance;
};


#endif //CATULA_BADGEDISTANCE_H

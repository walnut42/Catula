//
// Created by Lorenzo Nuti and Paolo Valcepina on 11/07/17.
//

#ifndef CATULA_BADGESPEED_H
#define CATULA_BADGESPEED_H

#include "ModelGame.h"
#include "MainCharacter.h"
#include "Badge.h"


class BadgeSpeed : public Badge {
public:
    BadgeSpeed(const std::string &className, const std::string &name, const std::string &description, float goal,
               bool memorize);

    virtual void update() override;

    virtual void detach() override;

private:
    virtual void attach() override;

    float speed;
};


#endif //CATULA_BADGESPEED_H

//
// Created by Lorenzo Nuti and Paolo Valcepina on 11/07/17.
//

#ifndef CATULA_BADGESTARSKULL_H
#define CATULA_BADGESTARSKULL_H

#include "ModelGame.h"
#include "MainCharacter.h"
#include "Badge.h"


class BadgeStarSkull : public Badge {
public:
    BadgeStarSkull(const std::string &className, const std::string &name, const std::string &description, float goal,
                   bool memorize);

    virtual void update() override;

    virtual void detach() override;

private:
    virtual void attach() override;

    int previousScore;
};


#endif //CATULA_BADGESTARSKULL_H

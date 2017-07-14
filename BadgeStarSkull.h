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
    BadgeStarSkull(const std::string &className, const std::string &name, const std::string &description, float goal,
                   bool memorize);

    virtual void update() override;

    virtual void detach() override;

    using Badge::attach;

protected:
    virtual void attach() override;

private:
    int previousScore;
};


#endif //CATULA_BADGESTARSKULL_H

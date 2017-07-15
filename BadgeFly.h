//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#ifndef CATULA_BADGEFLY_H
#define CATULA_BADGEFLY_H

#include "ModelGame.h"
#include "MainCharacter.h"
#include "Badge.h"


class BadgeFly : public Badge {
public:
    BadgeFly(const std::string &className, const std::string &name, const std::string &description, float goal,
             bool memorize);

    virtual void update() override;

    virtual void detach() override;

private:
    virtual void attach() override;

    bool top;
    float initDistance;
};


#endif //CATULA_BADGEFLY_H

//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#ifndef CATULA_BADGESKULL_H
#define CATULA_BADGESKULL_H

#include "Badge.h"
#include "MainCharacter.h"
#include "ModelGame.h"


class BadgeSkull : public Badge {
public:
    BadgeSkull(const std::string &className, const std::string &name, const std::string &description, float goal,
               bool memorize);

    virtual void update() override;

    virtual void detach() override;

    using Badge::attach;

protected:
    virtual void attach() override;

private:
    int previousScore;
    int score;
};


#endif //CATULA_BADGESKULL_H

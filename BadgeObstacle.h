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
    BadgeObstacle(const std::string &className, const std::string &name, const std::string &description, float goal,
                  bool memorize);

    virtual void update() override;

    virtual void detach() override;

    using Badge::attach;

protected:
    virtual void attach() override;

private:
    int previousScore;
    int previousLives;
};


#endif //CATULA_BADGEOBSTACLE_H

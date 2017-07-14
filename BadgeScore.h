//
// Created by Lorenzo Nuti and Paolo Valcepina on 11/07/17.
//

#ifndef CATULA_BADGESCORE_H
#define CATULA_BADGESCORE_H

#include "Badge.h"
#include "ModelGame.h"
#include "MainCharacter.h"


class BadgeScore : public Badge {
public:
    BadgeScore(const std::string &className, const std::string &name, const std::string &description, float goal,
               bool memorize);

    virtual void update() override;

    virtual void attach(MainCharacter *mC) override;

    virtual void detach() override;

private:
    int previousScore;
    int score;
};


#endif //CATULA_BADGESCORE_H

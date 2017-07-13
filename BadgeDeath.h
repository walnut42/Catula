//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#ifndef CATULA_BADGEDEATH_H
#define CATULA_BADGEDEATH_H

#include "Badge.h"

class BadgeDeath : public Badge {
public:
    BadgeDeath(MainCharacter *mC, float goal, bool m, float p);

    virtual ~BadgeDeath();

    virtual void update() override;

    virtual void attach() override;

    virtual void detach() override;

private:
    int previousLife;
    int life;
};

#endif //CATULA_BADGEDEATH_H

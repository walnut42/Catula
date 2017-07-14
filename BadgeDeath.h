//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#ifndef CATULA_BADGEDEATH_H
#define CATULA_BADGEDEATH_H

#include "Badge.h"

class BadgeDeath : public Badge {
public:
    BadgeDeath(const std::string &className, const std::string &name, const std::string &description, float goal,
               bool memorize);

    virtual void update() override;

    virtual void detach() override;

    using Badge::attach;

protected:
    virtual void attach() override;

private:
    int previousLife;
    int life;
};

#endif //CATULA_BADGEDEATH_H

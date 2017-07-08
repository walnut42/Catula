//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#ifndef CATULA_MODELBADGE_H
#define CATULA_MODELBADGE_H

#include "ModelBase.h"

class ModelBadge : public ModelBase {
public:
    ModelBadge();

    ~ModelBadge();

    virtual ModelBase *processInput(const sf::Event &event) override;

    virtual ModelBase *update() override;

    virtual void draw() override;

    virtual void enter() override;

    virtual void exit() override;

private:
    sf::Sprite background;

    sf::Text title;
    sf::Text content;
    sf::Clock clock;
};


#endif //CATULA_MODELBADGE_H

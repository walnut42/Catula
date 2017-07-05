//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#ifndef CATULA_MODELPAUSE_H
#define CATULA_MODELPAUSE_H

#include "ModelBase.h"


class ModelPause : public ModelBase {
public:
    ModelPause();

    ~ModelPause();

    virtual ModelBase *processInput(const sf::Event &event) override;

    virtual ModelBase *update() override;

    virtual void draw() override;

    virtual void enter() override;

    virtual void exit() override;

private:
    sf::RectangleShape backdrop;
    sf::Text content;
    sf::Sprite sprite;
    float posY;
};


#endif //CATULA_MODELPAUSE_H

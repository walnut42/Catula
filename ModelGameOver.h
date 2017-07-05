//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#ifndef CATULA_MODELGAMEOVER_H
#define CATULA_MODELGAMEOVER_H

#include "ModelBase.h"


class ModelGameOver : public ModelBase {
public:
    ModelGameOver();

    ~ModelGameOver();

    virtual ModelBase *processInput(const sf::Event &event) override;

    virtual ModelBase *update() override;

    virtual void draw() override;

    virtual void enter() override;

    virtual void exit() override;

private:
    sf::RectangleShape backdrop;
    sf::Text content;
    sf::Sound sound;
    sf::Sprite sprite;
    float opacity;
};


#endif //CATULA_MODELGAMEOVER_H

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
    sf::Clock clock;
    sf::Sound sound;
    sf::Music music;

    sf::RectangleShape selection;
    sf::Sprite background;
    sf::Text badgeDescription;
    sf::Text title;
    sf::Text content;
    const int barHeight = 9;
    const int margin = 50;
    const int padding = 5;
    int numberOfBadges;
    unsigned short int selected;
};


#endif //CATULA_MODELBADGE_H

//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/06/17.
//

#ifndef CATULA_MODELMENU_H
#define CATULA_MODELMENU_H


#include "ModelBase.h"

class ModelMenu : public ModelBase {
public:
    ModelMenu();

    ~ModelMenu();

    virtual ModelBase *processInput(const sf::Event &event) override;

    virtual ModelBase *update() override;

    virtual void draw() override;

    virtual void enter() override;

    virtual void exit() override;

private:
    sf::Font titleFont;
    sf::Text titleText;
    int titleY;
    float titleStopY;

    sf::Font contentFont;
    sf::Text contentText;

    sf::RectangleShape selection;
    unsigned short int selected;

    sf::Sprite character1;
    sf::Sprite character2;

    sf::Color textColor;

    sf::RectangleShape background;

    sf::Sound sound;
    sf::Music music;
};


#endif //CATULA_MODELMENU_H

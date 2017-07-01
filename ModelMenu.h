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

private:
    sf::Font titleFont;
    sf::Text titleText;
    int titleY;
    float titleStopY;

    sf::Font contentFont;
    sf::Text contentText;
    sf::Texture texture;

    sf::RectangleShape selection;
    unsigned short int selected;

    sf::Texture character1;
    sf::Texture character2;
    sf::Sprite character1Sprite;
    sf::Sprite character2Sprite;

    sf::Color baseColor;
};


#endif //CATULA_MODELMENU_H

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

    sf::Color textColor;

    sf::RectangleShape background;

    sf::SoundBuffer buffer;
    sf::Sound sound;

    sf::Music music;
};


#endif //CATULA_MODELMENU_H

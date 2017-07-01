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
    sf::RectangleShape backdrop;
    sf::Font font;
    sf::RectangleShape selection;
    sf::Text content;
    sf::Texture texture;
    sf::Texture character1;
    sf::Texture character2;
    sf::Sprite character1Sprite;
    sf::Sprite character2Sprite;
    sf::Sprite sprite;
    unsigned short int selected;
    float posY;
};


#endif //CATULA_MODELMENU_H

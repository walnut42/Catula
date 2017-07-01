//
// Created by lorenzo on 01/07/17.
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

private:
    sf::RectangleShape backdrop;
    sf::Font font;
    sf::Text content;
    sf::Texture texture;
    sf::Sprite sprite;
    float posY;
};


#endif //CATULA_MODELPAUSE_H

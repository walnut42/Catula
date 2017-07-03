//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/05/17.
//

#ifndef CATULA_TEXTBOX_H
#define CATULA_TEXTBOX_H


#include <SFML/Graphics.hpp>
#include "ModelGame.h"


class Textbox {
public:
    Textbox(ModelGame &modelGame);

    void draw();

    void update();

private:
    sf::RectangleShape backdrop;
    sf::Font font;
    sf::Text content;
    ModelGame &modelGame;
    sf::Sprite life;
    sf::Vector2f lifePos;
};


#endif //CATULA_TEXTBOX_H

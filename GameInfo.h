//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/05/17.
//

#ifndef CATULA_TEXTBOX_H
#define CATULA_TEXTBOX_H


#include <SFML/Graphics.hpp>
#include "ModelGame.h"


class GameInfo {
public:
    GameInfo(ModelGame &modelGame);

    void draw();

    void update();

private:
    sf::Text content;
    ModelGame &modelGame;
    sf::Sprite life;
    sf::Vector2f lifePos;
};


#endif //CATULA_TEXTBOX_H

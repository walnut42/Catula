//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/05/17.
//

#ifndef CATULA_TEXTBOX_H
#define CATULA_TEXTBOX_H

#include <SFML/Graphics.hpp>

#include "ModelGame.h"

class BadgeInfo;

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

    BadgeInfo *badge;
    sf::Clock clock;
    sf::Text badgeText;
    sf::RectangleShape badgeRect;
};


#endif //CATULA_TEXTBOX_H

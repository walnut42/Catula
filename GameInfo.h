//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/05/17.
//

#ifndef CATULA_TEXTBOX_H
#define CATULA_TEXTBOX_H

#include <SFML/Graphics.hpp>

#include "ModelGame.h"
#include "Badge.h"


class GameInfo {
public:
    GameInfo(ModelGame &modelGame);

    void draw();

    void update();

private:
    ModelGame &modelGame;
    sf::Sprite life;
    sf::Text content;
    sf::Vector2f lifePos;

    Badge *badge;
    sf::Clock clock;
    sf::RectangleShape badgeRect;
    sf::Text badgeText;
    sf::Sound sound;

    const int notifyHeight;
    float hWidth;
    const int paddingX;
    const int paddingY;
};


#endif //CATULA_TEXTBOX_H

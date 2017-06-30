//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/05/17.
//

#ifndef CATULA_TEXTBOX_H
#define CATULA_TEXTBOX_H


#include <SFML/Graphics.hpp>


class Textbox {
public:
    Textbox();

    void draw();

    void update();

private:
    sf::RectangleShape backdrop;
    sf::Font font;
    sf::Text content;
};


#endif //CATULA_TEXTBOX_H

//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/05/17.
//

#ifndef CATULA_TEXTBOX_H
#define CATULA_TEXTBOX_H


#include <SFML/Graphics.hpp>

class Window;

class Model;

class Textbox {
public:
    Textbox(Window *window, const Model &model);

    void draw(Window *window);

    void update();

private:
    sf::RectangleShape backdrop;
    sf::Font font;
    sf::Text content;
    const Model &model;
};


#endif //CATULA_TEXTBOX_H

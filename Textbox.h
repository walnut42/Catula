//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/05/17.
//

#ifndef CATULA_TEXTBOX_H
#define CATULA_TEXTBOX_H


#include <SFML/Graphics.hpp>

#include "Drawable.h"
#include "Window.h"

class Textbox : public Drawable {
public:
    static Textbox *getInstance();

    void draw() override;

    void update() override;

private:
    Textbox();

    sf::RectangleShape backdrop;
    sf::Font font;
    sf::Text content;
    static Textbox *instance;
};


#endif //CATULA_TEXTBOX_H

//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/05/17.
//

#ifndef CATULA_TEXTBOX_H
#define CATULA_TEXTBOX_H


#include <SFML/Graphics.hpp>

#include "Drawable.h"
#include "Window.h"
#include "MainCharacter.h"

class MainCharacter;
class Textbox : public Drawable {
public:
    Textbox(Window *window, MainCharacter *mainCharacter);

    void draw() override;

    void update() override;

private:
    sf::RectangleShape backdrop;
    sf::Font font;
    sf::Text content;

    MainCharacter *mainCharacter;
};


#endif //CATULA_TEXTBOX_H

//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/05/17.
//

#include "Textbox.h"
#include "Model.h"
#include "Window.h"

void Textbox::draw(Window *window) {
    backdrop.setSize(sf::Vector2f(window->getWidth(), 100));
    window->drawDrawable(backdrop);
    window->drawDrawable(content);
}

void Textbox::update() {
    if (model.getMainCharacter()->hasLost())
        content.setString("GAME OVER!"
                                  "\nYour score is: " + std::to_string(model.getMainCharacter()->getScore()));
    else
        content.setString("Score " + std::to_string(model.getMainCharacter()->getScore()) +
                          "\nLives " + std::to_string(model.getMainCharacter()->getLives()));
}

Textbox::Textbox(Window *window, const Model &model) : model{model} {
    font.loadFromFile("../Resources/FreeSerif.ttf");
    content.setFont(font);
    content.setCharacterSize(20);
    float s = window->getScale();
    content.setScale(s, s);
    content.setColor(sf::Color::Red);
    content.setPosition(100, 0);
    backdrop.setSize(sf::Vector2f(window->getWidth(), 100));
    backdrop.setFillColor(sf::Color(100, 100, 100, 100));
    backdrop.setPosition(0, 0);
}

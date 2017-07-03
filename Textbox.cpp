//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/05/17.
//

#include "Textbox.h"
#include "MainCharacter.h"
#include "Window.h"

Textbox::Textbox(ModelGame &modelGame) : modelGame{modelGame} {
    font.loadFromFile("../Resources/Font/FreeSerif.ttf");
    content.setFont(font);
    content.setCharacterSize(20);
    float s = Window::getInstance()->getScale();
    content.setScale(s, s);
    content.setColor(sf::Color::Red);
    content.setPosition(100, 0);
    backdrop.setSize(sf::Vector2f(Window::getWidth(), 100));
    backdrop.setFillColor(sf::Color(100, 100, 100, 100));
    backdrop.setPosition(0, 0);
    Images::setSprite(life, Image::Heart);
    lifePos = sf::Vector2f(Window::getWidth() - 100, 100);
}

void Textbox::draw() {
    backdrop.setSize(sf::Vector2f(Window::getWidth(), 100));
    Window::getInstance()->drawDrawable(backdrop);
    Window::getInstance()->drawDrawable(content);
    Window::getInstance()->drawSprite(life, lifePos);
}

void Textbox::update() {
    if (modelGame.hasLost())
        content.setString("GAME OVER!"
                                  "\nYour score is: " + std::to_string(modelGame.getScore()));
    else
        content.setString("Score " + std::to_string(modelGame.getScore()) +
                          "\nLives " + std::to_string(modelGame.getLives()));
}



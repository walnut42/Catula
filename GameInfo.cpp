//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/05/17.
//

#include "GameInfo.h"
#include "MainCharacter.h"
#include "Window.h"
#include "Background.h"
#include "Fonts.h"
#include <iomanip>

GameInfo::GameInfo(ModelGame &modelGame) : modelGame{modelGame} {
    Fonts::setText(content, Font::Score);
    content.setCharacterSize(30);
    float s = Window::getInstance()->getScale();
    content.setScale(s, s);
    content.setColor(sf::Color::Red);
    content.setPosition(100, 0);
    Images::setSprite(life, Image::Heart);
    lifePos = sf::Vector2f(Window::getWidth() - 70, 10);
}

void GameInfo::draw() {
    Window::getInstance()->drawDrawable(content);
    for (int i = 0; i < modelGame.getMainCharacter()->getLives(); ++i) {
        Window::getInstance()->drawSprite(life, lifePos + sf::Vector2f(-70 * i, 0));
    }
}

void GameInfo::update() {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << modelGame.getBackground()->getDistance();
    content.setString("Score: " + std::to_string(modelGame.getMainCharacter()->getScore()) +
                      "\t\tDistance: " + stream.str());
    lifePos = sf::Vector2f(Window::getWidth() - 70, 10);
}



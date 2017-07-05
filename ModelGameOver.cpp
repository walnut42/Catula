//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#include <sstream>
#include <iomanip>
#include "ModelGameOver.h"

#include "Window.h"
#include "Audio.h"
#include "Fonts.h"
#include "MainCharacter.h"
#include "Background.h"

ModelGameOver::ModelGameOver() : opacity{0} {
    Audio::setSound(sound, Sound::Fail);
    Fonts::setText(content, Font::Serif);
    content.setColor(sf::Color(150, 170, 230));
    content.setCharacterSize(25);
    content.setString("Press esc to go back to menu...");
    sf::FloatRect textRect = content.getGlobalBounds();
    content.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

    Fonts::setText(score, Font::Widow);
    score.setColor(sf::Color(150, 170, 230));
    score.setCharacterSize(75);
    std::stringstream stream;
    stream << std::fixed << std::setprecision(0) << Controller::modelGame->getBackground()->getDistance();
    score.setString("Your score is " + std::to_string(Controller::modelGame->getMainCharacter()->getScore()) + "    "
            "Your distance is " + stream.str());

    sf::FloatRect textRect2 = score.getGlobalBounds();
    score.setOrigin(textRect2.left + textRect2.width / 2.0f, textRect2.top + textRect2.height / 2.0f);

    backdrop.setPosition(0, 0);
    Images::setSprite(sprite, Image::GameOver);

    sprite.setOrigin(sprite.getTextureRect().width / 2, 0);
    backdrop.setFillColor(sf::Color(0, 0, 0, static_cast<sf::Uint8>(opacity)));
    content.setPosition(Window::getWidth() / 2.0f, Window::getHeight() * 7 / 8.0f);
    score.setPosition(Window::getWidth() / 2.0f, Window::getHeight() * 3.0f / 4.0f);

    backdrop.setSize(sf::Vector2f(Window::getWidth(), Window::getHeight()));
    sprite.setPosition(Window::getWidth() / 2, Window::getHeight() / 7);
}

ModelGameOver::~ModelGameOver() {

}

ModelBase *ModelGameOver::processInput(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        return getModel(Controller::modelMenu);
    } else
        return nullptr;
}

ModelBase *ModelGameOver::update() {
    if (opacity < 255)
        opacity += 0.3;
    backdrop.setFillColor(sf::Color(0, 0, 0, static_cast<sf::Uint8>(opacity)));
    content.setPosition(Window::getWidth() / 2.0f, Window::getHeight() * 7 / 8.0f);
    score.setPosition(Window::getWidth() / 2.0f, Window::getHeight() * 3.0f / 4.0f);

    backdrop.setSize(sf::Vector2f(Window::getWidth(), Window::getHeight()));
    sprite.setPosition(Window::getWidth() / 2, Window::getHeight() / 7);
    return nullptr;
}

void ModelGameOver::draw() {
    Window::getInstance()->setDrawPrevision(false);
    Controller::modelGame->draw();
    Window::getInstance()->setDrawPrevision(true);

    Window::getInstance()->drawDrawable(backdrop);

    Window::getInstance()->drawDrawable(content);
    Window::getInstance()->drawDrawable(score);
    Window::getInstance()->drawDrawable(sprite);
}

void ModelGameOver::enter() {
    sound.play();
    opacity = 0;
}

void ModelGameOver::exit() {

}

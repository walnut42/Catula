//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#include "ModelGameOver.h"
#include "Window.h"
#include "Audio.h"

ModelGameOver::ModelGameOver() {
    Audio::setSound(sound, Sound::Fail);
    font.loadFromFile("../Resources/Font/FreeSerif.ttf");
    content.setFont(font);
    content.setColor(sf::Color::Red);
    content.setCharacterSize(200);
    content.setString("Game Over");
    sf::FloatRect textRect = content.getGlobalBounds();
    content.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    content.setPosition(Window::getWidth() / 2, Window::getHeight() / 2);

    backdrop.setFillColor(sf::Color(0, 0, 0, 180));
    backdrop.setPosition(0, 0);
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
    content.setPosition(Window::getWidth() / 2.0f, Window::getHeight() / 2.0f);
    backdrop.setSize(sf::Vector2f(Window::getWidth(), Window::getHeight()));

    return nullptr;
}

void ModelGameOver::draw() {
    Window::getInstance()->setDrawPrevision(false);
    Controller::modelGame->draw();
    Window::getInstance()->setDrawPrevision(true);

    Window::getInstance()->drawDrawable(backdrop);

    Window::getInstance()->drawDrawable(content);
}

void ModelGameOver::enter() {
    sound.play();
}

void ModelGameOver::exit() {

}

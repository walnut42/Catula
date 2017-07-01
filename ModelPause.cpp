//
// Created by lorenzo on 01/07/17.
//

#include "ModelPause.h"
#include "Window.h"

ModelPause::ModelPause() : posY{0} {

    font.loadFromFile("../Resources/FreeSerif.ttf");
    content.setFont(font);
    content.setCharacterSize(20);
    content.setColor(sf::Color::Red);
    content.setCharacterSize(20);
    content.setString("Pause! Press enter to play...");
    sf::FloatRect textRect = content.getGlobalBounds();
    content.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    content.setPosition(Window::getWidth() / 2, Window::getHeight() / 2);
    texture.loadFromFile("../Resources/Intro.png");
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y);
    sprite.setPosition(Window::getWidth() / 2, posY);

    backdrop.setFillColor(sf::Color(0, 0, 0, 180));
    backdrop.setPosition(0, 0);
}

ModelPause::~ModelPause() {

}

ModelBase *ModelPause::processInput(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
        return getModel(Controller::modelGame);
    } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        return getModel(Controller::modelMenu);
    } else
        return nullptr;
}

ModelBase *ModelPause::update() {
    if (posY < Window::getHeight() / 2)
        sprite.setPosition(Window::getWidth() / 2, ++posY);
    content.setPosition(Window::getWidth() / 2.0f,
                        Window::getHeight() / 2.0f + texture.getSize().y / 2.0f);
    backdrop.setSize(sf::Vector2f(Window::getWidth(), Window::getHeight()));

    return nullptr;
}

void ModelPause::draw() {
    Window::getInstance()->setDrawPrevision(false);
    Controller::modelGame->draw();
    Window::getInstance()->setDrawPrevision(true);

    Window::getInstance()->drawDrawable(backdrop);

    Window::getInstance()->drawDrawable(sprite);
    if (posY >= Window::getHeight() / 2) {
        Window::getInstance()->drawDrawable(content);
    }
}

void ModelPause::enter() {
    posY = 0;
}

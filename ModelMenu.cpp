//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/06/17.
//

#include "ModelMenu.h"
#include "Window.h"

ModelMenu::ModelMenu() {
    font.loadFromFile("../Resources/FreeSerif.ttf");
    content.setFont(font);
    content.setCharacterSize(20);
    float s = Window::getInstance()->getScale();
    content.setScale(s, s);
    content.setColor(sf::Color::Red);
    backdrop.setSize(sf::Vector2f(300, 100));
    backdrop.setFillColor(sf::Color(100, 100, 100, 100));
    backdrop.setPosition(Window::getWidth() / 2 - backdrop.getSize().x / 2,
                         Window::getHeight() / 2 - backdrop.getSize().y / 2);
    content.setPosition(Window::getWidth() / 2 - backdrop.getSize().x / 2,
                        Window::getHeight() / 2 - backdrop.getSize().y / 2);
    content.setString("Press enter!");
}

ModelMenu::~ModelMenu() {

}

ModelBase *ModelMenu::processInput(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
        return new ModelGame();
    else
        return nullptr;
}

ModelBase *ModelMenu::update() {
    backdrop.setPosition(Window::getWidth() / 2 - backdrop.getSize().x / 2,
                         Window::getHeight() / 2 - backdrop.getSize().y / 2);
    content.setPosition(Window::getWidth() / 2 - 60, Window::getHeight() / 2 - 20);
    return nullptr;
}

void ModelMenu::draw() {
    Window::getInstance()->drawDrawable(backdrop);
    Window::getInstance()->drawDrawable(content);
}

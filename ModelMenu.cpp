//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/06/17.
//

#include "ModelMenu.h"
#include "Window.h"

ModelMenu::ModelMenu() : posY{0} {

    font.loadFromFile("../Resources/FreeSerif.ttf");
    content.setFont(font);
    content.setCharacterSize(20);
    content.setColor(sf::Color::Red);
    content.setCharacterSize(20);
    content.setString("Press enter to play...");
    sf::FloatRect textRect = content.getGlobalBounds();
    content.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    content.setPosition(Window::getWidth() / 2, Window::getHeight() / 2);
    texture.loadFromFile("../Resources/Intro.png");
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y);
    sprite.setPosition(Window::getWidth() / 2, posY);

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
    if (posY < Window::getHeight() / 2)
        sprite.setPosition(Window::getWidth() / 2, ++posY);
    content.setPosition(Window::getWidth() / 2.0f,
                        Window::getHeight() / 2.0f + texture.getSize().y / 2.0f);
    return nullptr;
}

void ModelMenu::draw() {
    Window::getInstance()->drawDrawable(sprite);
    if (posY >= Window::getHeight() / 2) {
        Window::getInstance()->drawDrawable(content);
    }
}

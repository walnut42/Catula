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
    character1.loadFromFile("../Resources/Catula.png");
    character1Sprite.setTexture(character1);
    character1Sprite.setPosition(Window::getWidth() / 4.0f, Window::getHeight() / 2.0f);
    character2.loadFromFile("../Resources/Mushroom.png");
    character2Sprite.setTexture(character2);
    character2Sprite.setPosition(Window::getWidth() * 3.0f / 4.0f, Window::getHeight() / 2.0f);
}

ModelMenu::~ModelMenu() {

}

ModelBase *ModelMenu::processInput(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
        return new ModelGame();
    if (event.type == sf::Event::MouseButtonPressed &&
        character1Sprite.getPosition().x - character1.getSize().x / 2 < sf::Mouse::getPosition().x &&
        character1Sprite.getPosition().x + character1.getSize().x / 2 > sf::Mouse::getPosition().x &&
        character1Sprite.getPosition().y - character1.getSize().y / 2 < sf::Mouse::getPosition().y &&
        character1Sprite.getPosition().y + character1.getSize().y / 2 > sf::Mouse::getPosition().y) {
        return new ModelGame("../Resources/Catula.png");
    } else
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
    Window::getInstance()->drawDrawable(character1Sprite);
    Window::getInstance()->drawDrawable(character2Sprite);
}

//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/06/17.
//

#include "ModelMenu.h"
#include "Window.h"

enum {
    Catula = 1, Mushroom = 3
};

ModelMenu::ModelMenu() : baseColor{153, 144, 240}, titleStopY{2.5}, titleY{0}, selected{1} {
    titleFont.loadFromFile("../Resources/BlackWidow.ttf");
    titleText.setFont(titleFont);
    titleText.setCharacterSize(200);
    titleText.setColor(baseColor);
    titleText.setString("CATULA");
    sf::FloatRect titleRect = titleText.getGlobalBounds();
    titleText.setOrigin(titleRect.left + titleRect.width / 2.0f,
                        titleRect.top + titleRect.height / 2.0f);

    contentFont.loadFromFile("../Resources/FreeSerif.ttf");
    contentText.setFont(contentFont);
    contentText.setCharacterSize(30);
    contentText.setColor(baseColor);
    contentText.setString("Choose the character and play...");
    sf::FloatRect textRect = contentText.getGlobalBounds();
    contentText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

    character1.loadFromFile("../Resources/Catula.png");
    character1Sprite.setTexture(character1);
    character1Sprite.setOrigin(character1.getSize().x / 2.0f, character1.getSize().y / 2.0f);

    character2.loadFromFile("../Resources/Mushroom.png");
    character2Sprite.setTexture(character2);
    character2Sprite.setOrigin(character2.getSize().x / 2.0f, character2.getSize().y / 2.0f);

    selection.setSize(sf::Vector2f(300, 300));
    selection.setFillColor(sf::Color::Transparent);
    selection.setOutlineColor(baseColor);
    selection.setOutlineThickness(5);
    selection.setOrigin(selection.getSize().x / 2.0f, selection.getSize().y / 2.0f);
}

ModelMenu::~ModelMenu() {

}

ModelBase *ModelMenu::processInput(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
        if (selected == Mushroom) {
            Controller::modelGame.reset(new ModelGame("../Resources/Mushroom.png"));
        } else
            Controller::modelGame.reset(new ModelGame);
        return Controller::modelGame.get();
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
        selection.setPosition(Window::getWidth() / 4.0f, Window::getHeight() / 2.0f);
        selected = Catula;
        return nullptr;
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
        selection.setPosition(Window::getWidth() * 3.0f / 4.0f, Window::getHeight() / 2.0f);
        selected = Mushroom;
        return nullptr;
    } else
        return nullptr;
}

ModelBase *ModelMenu::update() {
    if (titleY < Window::getHeight() / titleStopY)
        titleText.setPosition(Window::getWidth() / 2.0f, ++titleY);
    else
        titleText.setPosition(Window::getWidth() / 2.0f, Window::getHeight() / titleStopY);
    contentText.setPosition(Window::getWidth() / 2.0f,
                            Window::getHeight() / 2.0f + texture.getSize().y / 2.0f);
    character1Sprite.setPosition(Window::getWidth() / 4.0f, Window::getHeight() / 2.0f);
    character2Sprite.setPosition(Window::getWidth() * 3.0f / 4.0f, Window::getHeight() / 2.0f);
    selection.setPosition(Window::getWidth() * selected / 4.0f, Window::getHeight() / 2.0f);
    return nullptr;
}

void ModelMenu::draw() {
    Window::getInstance()->drawDrawable(titleText);
    if (titleY >= Window::getHeight() / titleStopY) {
        Window::getInstance()->drawDrawable(contentText);
    }
    Window::getInstance()->drawDrawable(character1Sprite);
    Window::getInstance()->drawDrawable(character2Sprite);
    Window::getInstance()->drawDrawable(selection);
}

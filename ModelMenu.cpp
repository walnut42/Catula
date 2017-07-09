//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/06/17.
//

#include "ModelMenu.h"

#include "Window.h"
#include "Audio.h"
#include "Fonts.h"

enum {
    Catula = 1, CatPumpkin = 3
};

ModelMenu::ModelMenu() : textColor{14, 1, 140}, titleStopY{2.5}, titleY{0}, selected{1} {
    Audio::setMusic(music, Music::Menu);
    music.setLoop(true);

    Audio::setSound(sound, Sound::Menu);

    Images::setSprite(background, Image::MenuBg);
    background.setPosition(0, 0);

    Fonts::setText(titleText, Font::BlackWidow);
    titleText.setCharacterSize(200);
    titleText.setColor(textColor);
    titleText.setString("CATULA");
    sf::FloatRect titleRect = titleText.getGlobalBounds();
    titleText.setOrigin(titleRect.left + titleRect.width / 2.0f,
                        titleRect.top + titleRect.height / 2.0f);

    Fonts::setText(contentText, Font::Serif);
    contentText.setCharacterSize(30);
    contentText.setColor(textColor);
    contentText.setString("Choose the character and play.\nPress b to see badges.");
    sf::FloatRect textRect = contentText.getGlobalBounds();
    contentText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

    Images::setSprite(character1, Image::Catula);
    character1.setOrigin(character1.getTextureRect().width / 2.0f, character1.getTextureRect().height / 2.0f);

    Images::setSprite(character2, Image::CatPumpkin);
    character2.setOrigin(character2.getTextureRect().width / 2.0f, character2.getTextureRect().height / 2.0f);

    selection.setSize(sf::Vector2f(300, 300));
    selection.setFillColor(sf::Color::Transparent);
    selection.setOutlineColor(textColor);
    selection.setOutlineThickness(5);
    selection.setOrigin(selection.getSize().x / 2.0f, selection.getSize().y / 2.0f);
}

ModelMenu::~ModelMenu() {

}

ModelBase *ModelMenu::processInput(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
        if (selected == CatPumpkin)
            return newModel(Controller::modelGame, Image::CatPumpkin);
        else
            return newModel(Controller::modelGame);
    } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
        selection.setPosition(Window::getWidth() / 4.0f, Window::getHeight() / 2.0f);
        selected = Catula;
        sound.play();
    } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
        selection.setPosition(Window::getWidth() * 3.0f / 4.0f, Window::getHeight() / 2.0f);
        selected = CatPumpkin;
        sound.play();
    } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B) {
        return getModel(Controller::modelBadge);
    }
    return nullptr;
}

ModelBase *ModelMenu::update() {
    if (titleY < Window::getHeight() / titleStopY)
        titleText.setPosition(Window::getWidth() / 2.0f, ++titleY);
    else
        titleText.setPosition(Window::getWidth() / 2.0f, Window::getHeight() / titleStopY);
    sf::Vector2f targetSize(Window::getWidth(), Window::getHeight());
    background.setScale(targetSize.x / background.getTextureRect().width,
                        targetSize.y / background.getTextureRect().height);
    contentText.setPosition(Window::getWidth() / 2.0f,
                            Window::getHeight() / 2.0f);
    character1.setPosition(Window::getWidth() / 4.0f, Window::getHeight() / 2.0f);
    character2.setPosition(Window::getWidth() * 3.0f / 4.0f, Window::getHeight() / 2.0f);
    selection.setPosition(Window::getWidth() * selected / 4.0f, Window::getHeight() / 2.0f);
    return nullptr;
}

void ModelMenu::draw() {
    Window::getInstance()->drawDrawable(background);

    Window::getInstance()->drawDrawable(titleText);
    if (titleY >= Window::getHeight() / titleStopY) {
        Window::getInstance()->drawDrawable(contentText);
    }
    Window::getInstance()->drawDrawable(character1);
    Window::getInstance()->drawDrawable(character2);
    Window::getInstance()->drawDrawable(selection);


}

void ModelMenu::enter() {
    music.play();
    titleY = 0;
}

void ModelMenu::exit() {
    music.stop();
}

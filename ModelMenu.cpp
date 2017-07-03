//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/06/17.
//

#include "ModelMenu.h"

#include "Window.h"
#include "Audio.h"

enum {
    Catula = 1, Mushroom = 3
};

ModelMenu::ModelMenu() : textColor{153, 144, 240}, titleStopY{2.5}, titleY{0}, selected{1} {
    Audio::setMusic(music, Music::Menu);
    music.setLoop(true);

    Audio::setSound(sound, Sound::Menu);

    background.setFillColor(sf::Color(11, 11, 12, 180));
    background.setPosition(0, 0);

    titleFont.loadFromFile("../Resources/Font/blackWidow.ttf");
    titleText.setFont(titleFont);
    titleText.setCharacterSize(200);
    titleText.setColor(textColor);
    titleText.setString("CATULA");
    sf::FloatRect titleRect = titleText.getGlobalBounds();
    titleText.setOrigin(titleRect.left + titleRect.width / 2.0f,
                        titleRect.top + titleRect.height / 2.0f);

    contentFont.loadFromFile("../Resources/Font/FreeSerif.ttf");
    contentText.setFont(contentFont);
    contentText.setCharacterSize(30);
    contentText.setColor(textColor);
    contentText.setString("Choose the character and play...");
    sf::FloatRect textRect = contentText.getGlobalBounds();
    contentText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

    Images::setSprite(character1, Image::Catula);
    character1.setOrigin(character1.getTextureRect().width / 2.0f, character1.getTextureRect().height / 2.0f);

    Images::setSprite(character2, Image::Mushroom);
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
        if (selected == Mushroom) {
            music.stop();
            return newModel(Controller::modelGame, Image::Mushroom);
        } else {
            music.stop();
            return newModel(Controller::modelGame);
        }
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
        selection.setPosition(Window::getWidth() / 4.0f, Window::getHeight() / 2.0f);
        selected = Catula;
        sound.play();
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
        selection.setPosition(Window::getWidth() * 3.0f / 4.0f, Window::getHeight() / 2.0f);
        selected = Mushroom;
        sound.play();
    }
    return nullptr;
}

ModelBase *ModelMenu::update() {
    if (titleY < Window::getHeight() / titleStopY)
        titleText.setPosition(Window::getWidth() / 2.0f, ++titleY);
    else
        titleText.setPosition(Window::getWidth() / 2.0f, Window::getHeight() / titleStopY);
    background.setSize(sf::Vector2f(Window::getWidth(), Window::getHeight()));
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
    if (music.getStatus() != sf::SoundSource::Status::Playing)
        music.play();
    titleY = 0;
}

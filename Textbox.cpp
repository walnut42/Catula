//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/05/17.
//

#include "Textbox.h"
// costruttore

Textbox *Textbox::instance = nullptr;

Textbox *Textbox::getInstance() {
    if (instance == nullptr)
        instance = new Textbox;
    return instance;
}

void Textbox::update() {
    std::string string;
    for (auto &itr : messages) {
        string.append(itr + "\n");
    }
    if (string != "") {
        content.setString(string);
    }
}

void Textbox::draw() {
    backdrop.setSize(sf::Vector2f(Window::getWidth(), 100));
    Window::getInstance()->drawDrawable(backdrop);
    Window::getInstance()->drawDrawable(content);
}

void Textbox::add(std::string message) {
    messages.push_back(message);
    if (messages.size() > 5) {
        messages.erase(messages.begin());
    }
}

Textbox::Textbox() {
    font.loadFromFile("../Resources/FreeSerif.ttf");
    content.setFont(font);
    content.setCharacterSize(20);
    float s = Window::getInstance()->getScale();
    content.setScale(s, s);
    content.setColor(sf::Color::Red);
    backdrop.setSize(sf::Vector2f(Window::getWidth(), 100));
    backdrop.setFillColor(sf::Color(100, 100, 100, 100));
    backdrop.setPosition(0, 0);
}

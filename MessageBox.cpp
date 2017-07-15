//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/04/17.
//

#include "MessageBox.h"

MessageBox::MessageBox(const std::string &title) {
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    window.create(sf::VideoMode(400, 200), title, sf::Style::Default);

    font.loadFromFile("../Resources/Font/FreeSerif.ttf");
    content.setFont(font);
    content.setCharacterSize(20);
    content.setColor(sf::Color::Black);
    content.setPosition(100, 0);
}

void MessageBox::draw() {
    window.clear(sf::Color::White);
    window.draw(content);
    window.display();
}

void MessageBox::showMessage(const std::string &message) {
    content.setString(message);
    while (window.isOpen()) {
        processInput();
        draw();
    }
}


void MessageBox::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed ||
            event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
            window.close();
        } else if (event.type == sf::Event::Resized) {
            window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
        }
    }
}
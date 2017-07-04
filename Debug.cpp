//
// Created by Lorenzo Nuti and Paolo Valcepina on 31/03/17.
//

#include "Debug.h"
#include "Fonts.h"

Debug *Debug::instance = nullptr;

Debug::Debug() {
    Fonts::setText(text, Font::Serif);
    text.setCharacterSize(20);
    text.setColor(sf::Color::Red);
}

Debug *Debug::getInstance() {
    if (instance == nullptr) {
        instance = new Debug;
    }
    return instance;
}

void Debug::setSpeed(sf::Time &elapsed) {
    elapsed = sf::seconds(elapsed.asSeconds() * speed);
}

void Debug::DrawText(sf::RenderWindow &window) {
    if (interval == 0 || clock.getElapsedTime().asSeconds() > interval) {
        std::string s = "";
        for (const auto &pair : debug) {
            s += pair.first + ": " + pair.second + "\n";
        }
        text.setString(s);

        clock.restart();
    }
    window.draw(text);
}
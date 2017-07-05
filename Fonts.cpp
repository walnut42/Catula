//
// Created by lorenzo on 04/07/17.
//

#include "Fonts.h"

std::map<Font, sf::Font> Fonts::fonts;

void Fonts::loadFonts() {
    const std::string path = "../Resources/Font/";
    fonts[Font::Widow].loadFromFile(path + "blackWidow.ttf");
    fonts[Font::Serif].loadFromFile(path + "FreeSerif.ttf");
    fonts[Font::Score].loadFromFile(path + "score.ttf");
}

void Fonts::setText(sf::Text &text, Font name) {
    text.setFont(fonts[name]);
}


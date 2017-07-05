//
// Created by lorenzo on 04/07/17.
//

#include "Fonts.h"
#include "LoadFileError.h"

std::map<Font, sf::Font> Fonts::fonts;

void Fonts::loadFonts() {
    const std::string error = "Error in font loading";
    //Fonts
    const std::string path = "../Resources/Font/";

    std::map<Font, std::string> fontList = {
            {Font::Widow, "blackWidow.ttf"},
            {Font::Serif, "FreeSerif.ttf"},
            {Font::Score, "score.ttf"},
    };

    for (const auto &font:fontList)
        if (!fonts[font.first].loadFromFile(path + font.second))
            throw LoadFileError(error, path, font.second);
}

void Fonts::setText(sf::Text &text, Font name) {
    text.setFont(fonts[name]);
}


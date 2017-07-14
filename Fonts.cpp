//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/07/17.
//

#include "Fonts.h"

std::map<Font, sf::Font> Fonts::fonts;

void Fonts::loadFonts() throw(load_file_error) {
    const std::string error = "Error in font loading";

    // Fonts.
    const std::string path = "../Resources/Font/";

    std::map<Font, std::string> fontList = {
            {Font::BlackWidow, "blackWidow.ttf"},
            {Font::Serif,      "FreeSerif.ttf"},
            {Font::Score,      "score.ttf"},
    };

    for (const auto &i:fontList)
        if (!fonts[i.first].loadFromFile(path + i.second))
            throw load_file_error(error, path, i.second);
}

void Fonts::setText(sf::Text &text, Font name) {
    text.setFont(fonts[name]);
}


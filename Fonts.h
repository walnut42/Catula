//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/07/17.
//

#ifndef CATULA_FONTS_H
#define CATULA_FONTS_H

#include <SFML/Graphics.hpp>
#include <map>

#include "load_file_error.h"


enum class Font {
    BlackWidow, Serif, Score
};

class Fonts {
public:
    static void loadFonts() throw(load_file_error);

    static void setText(sf::Text &text, Font name);

private:
    Fonts() {};
    static std::map<Font, sf::Font> fonts;
};


#endif //CATULA_FONTS_H

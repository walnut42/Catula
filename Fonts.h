//
// Created by lorenzo on 04/07/17.
//

#ifndef CATULA_FONTS_H
#define CATULA_FONTS_H

#include <map>
#include <SFML/Graphics.hpp>

enum class Font {
    Widow, Serif, Score
};


class Fonts {
public:
    static void loadFonts();

    static void setText(sf::Text &text, Font name);

private:
    Fonts() {};
    static std::map<Font, sf::Font> fonts;
};

#endif //CATULA_FONTS_H

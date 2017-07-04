//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#ifndef CATULA_IMAGES_H
#define CATULA_IMAGES_H


#include <map>
#include <SFML/Graphics.hpp>


enum class Image {
    Intro,

    // The order is important for the background random generator!
            CavBg = 1, Cav2CemBg, Cav2HalBg,
    Cem2CavBg, CemBg, Cem2HalBg,
    Hal2CavBg, Hal2CemBg, HalBg,

    Catula, Mushroom, Heart,
    Laser, Star, Rocket, GameOver, MenuBg
};


class Images {
public:
    static void loadImages(bool smooth = true);

    static void setSprite(sf::Sprite &sprite, Image name);

    static const int getNumberBg();
private:
    Images() {};
    static std::map<Image, sf::Texture> textures;
    static const int numberBg = 3;
};


#endif //CATULA_IMAGES_H

//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#ifndef CATULA_IMAGES_H
#define CATULA_IMAGES_H

#include <SFML/Graphics.hpp>
#include <map>
#include "LoadFileError.h"


enum class Image {
    // The order is important for the background random generator!
            CavBg = 1, Cav2CemBg, Cav2HalBg,
    Cem2CavBg, CemBg, Cem2HalBg,
    Hal2CavBg, Hal2CemBg, HalBg,

    Catula, CatPumpkin, Heart,
    Laser, Skull, Star, Rocket, GameOver, MenuBg
};

class Images {
public:
    static void loadImages(bool smooth = true) throw(LoadFileError);

    static void setSprite(sf::Sprite &sprite, Image name);

    static const int getNumberBg();

private:
    Images() {};
    static std::map<Image, sf::Texture> textures;
    static const int numberBg = 3;
};


#endif //CATULA_IMAGES_H

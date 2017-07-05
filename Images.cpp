//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#include "Images.h"
#include "LoadFileError.h"

std::map<Image, sf::Texture> Images::textures;

void Images::loadImages(bool smooth) {
    const std::string error = "Error in image loading";

    const std::string path = "../Resources/Images/";

    std::map<Image, std::string> imageList = {
            {Image::Intro,      "intro.ogg"},

            {Image::CavBg,      "cav.ogg"},
            {Image::CemBg,      "cem.ogg"},
            {Image::HalBg,      "hal.ogg"},
            {Image::Cav2CemBg,  "cav2cem.ogg"},
            {Image::Cav2HalBg,  "cav2hal.ogg"},
            {Image::Cem2CavBg,  "cem2cav.ogg"},
            {Image::Cem2HalBg,  "cem2hal.ogg"},
            {Image::Hal2CavBg,  "hal2cav.ogg"},
            {Image::Hal2CemBg,  "hal2cem.ogg"},

            {Image::Catula,     "catula.ogg"},
            {Image::CatPumpkin, "catPumpkin.ogg"},
            {Image::Heart,      "heart.ogg"},
            {Image::Laser,      "laser.ogg"},
            {Image::Skull,      "skull.ogg"},
            {Image::Star,       "star.ogg"},
            {Image::Rocket,     "rocket.ogg"},
            {Image::GameOver,   "gameOver.ogg"},
            {Image::MenuBg,     "menuBg.ogg"},
    };

    for (const auto &image:imageList) {
        if (!textures[image.first].loadFromFile(path + image.second))
            throw LoadFileError(error, path, image.second);
        else
            textures[image.first].setSmooth(smooth);
    }
}

void Images::setSprite(sf::Sprite &sprite, Image name) {
    sprite.setTexture(textures[name]);
}

const int Images::getNumberBg() {
    return numberBg;
}

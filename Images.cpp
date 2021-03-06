//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#include "Images.h"

std::map<Image, sf::Texture> Images::textures;

void Images::loadImages(bool smooth) throw(load_file_error) {
    const std::string error = "Error in image loading";

    const std::string path = "../Resources/Images/";

    std::map<Image, std::string> imageList = {
            {Image::CavBg,       "cav.png"},
            {Image::CemBg,       "cem.png"},
            {Image::HalBg,       "hal.png"},
            {Image::Cav2CemBg,   "cav2cem.png"},
            {Image::Cav2HalBg,   "cav2hal.png"},
            {Image::Cem2CavBg,   "cem2cav.png"},
            {Image::Cem2HalBg,   "cem2hal.png"},
            {Image::Hal2CavBg,   "hal2cav.png"},
            {Image::Hal2CemBg,   "hal2cem.png"},

            {Image::Catula,      "catula.png"},
            {Image::CatPumpkin,  "catPumpkin.png"},
            {Image::Heart,       "heart.png"},
            {Image::Laser,       "laser.png"},
            {Image::Skull,       "skull.png"},
            {Image::Star,        "star.png"},
            {Image::Rocket,      "rocket.png"},
            {Image::GameOver,    "gameOver.png"},
            {Image::MenuBg,      "menuBg.png"},

            {Image::BadgeBg,     "badgeBg.png"},
            {Image::BadgeLocked, "badgeLocked.png"},
            {Image::Bar,         "bar.png"},
            {Image::BarEmpty,    "barEmpty.png"}
    };

    for (const auto &i:imageList) {
        if (!textures[i.first].loadFromFile(path + i.second))
            throw load_file_error(error, path, i.second);
        else
            textures[i.first].setSmooth(smooth);
    }
}

void Images::setSprite(sf::Sprite &sprite, Image name) {
    sprite.setTexture(textures[name]);
}

const int Images::getNumberBg() {
    return numberBg;
}

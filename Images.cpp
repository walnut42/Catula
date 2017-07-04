//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#include "Images.h"


std::map<Image, sf::Texture> Images::textures;


void Images::loadImages(bool smooth) {
    const std::string path = "../Resources/Images/";

    textures[Image::Intro].loadFromFile(path + "intro.png");

    textures[Image::CavBg].loadFromFile(path + "cav.png");
    textures[Image::CemBg].loadFromFile(path + "cem.png");
    textures[Image::HalBg].loadFromFile(path + "hal.png");
    textures[Image::Cav2CemBg].loadFromFile(path + "cav2cem.png");
    textures[Image::Cav2HalBg].loadFromFile(path + "cav2hal.png");
    textures[Image::Cem2CavBg].loadFromFile(path + "cem2cav.png");
    textures[Image::Cem2HalBg].loadFromFile(path + "cem2hal.png");
    textures[Image::Hal2CavBg].loadFromFile(path + "hal2cav.png");
    textures[Image::Hal2CemBg].loadFromFile(path + "hal2cem.png");

    textures[Image::Catula].loadFromFile(path + "catula.png");
    textures[Image::Mushroom].loadFromFile(path + "mushroom.png");
    textures[Image::Heart].loadFromFile(path + "heart.png");
    textures[Image::Laser].loadFromFile(path + "laser.png");
    textures[Image::Star].loadFromFile(path + "star.png");
    textures[Image::Rocket].loadFromFile(path + "rocket.png");

    textures[Image::GameOver].loadFromFile(path + "gameOver.png");
    textures[Image::MenuBg].loadFromFile(path + "menuBg.png");


    for (auto &texture:textures) {
        texture.second.setSmooth(smooth);
    }
}

void Images::setSprite(sf::Sprite &sprite, Image name) {
    sprite.setTexture(textures[name]);
}

const int Images::getNumberBg() {
    return numberBg;
}



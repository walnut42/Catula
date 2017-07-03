//
// Created by lorenzo on 03/07/17.
//

#include "Images.h"


std::map<Image, sf::Texture> Images::textures;


void Images::loadImages(bool smooth) {
    const std::string path = "../Resources/Images/";
    textures[Image::CemeteryBk].loadFromFile(path + "cem.png");
    textures[Image::SunBk].loadFromFile(path + "sunAndSand.png");
    textures[Image::Laser].loadFromFile(path + "laser.png");
    textures[Image::Star].loadFromFile(path + "star.png");
    textures[Image::Rocket].loadFromFile(path + "rocket.png");
    textures[Image::Intro].loadFromFile(path + "intro.png");
    textures[Image::Catula].loadFromFile(path + "catula.png");
    textures[Image::Mushroom].loadFromFile(path + "mushroom.png");
    textures[Image::Heart].loadFromFile(path + "heart.png");


    for (auto &texture:textures) {
        texture.second.setSmooth(smooth);
    }
}

void Images::setSprite(sf::Sprite &sprite, Image name) {
    sprite.setTexture(textures[name]);
}



//
// Created by lorenzo on 03/07/17.
//

#ifndef CATULA_IMAGES_H
#define CATULA_IMAGES_H


#include <map>
#include <SFML/Graphics.hpp>


enum class Image {
    CemeteryBk, SunBk, Laser, Star, Rocket, Intro, Catula, Mushroom, Heart
};


class Images {
public:
    static void loadImages(bool smooth = true);

    static void setSprite(sf::Sprite &sprite, Image name);

private:
    Images() {};
    static std::map<Image, sf::Texture> textures;
};


#endif //CATULA_IMAGES_H

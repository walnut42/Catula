//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/03/17.
//

#include <SFML/Graphics.hpp>

#include "Window.h"
#include "Audio.h"
#include "Fonts.h"

int main() {
    srand((unsigned int) (time(NULL)));

    Audio::loadSounds();
    Images::loadImages();
    Fonts::loadFonts();

    Window::getInstance();
    Controller controller;
    Window::getInstance()->gameLoop(controller);
    return 0;
}

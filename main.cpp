//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/03/17.
//

#include <SFML/Graphics.hpp>

#include "Window.h"
#include "Audio.h"
#include "Fonts.h"
#include "LoadFileError.h"

int main() {
    srand((unsigned int) (time(NULL)));

    try {
        Audio::loadSounds();
        Images::loadImages();
        Fonts::loadFonts();
    }
    catch (const LoadFileError &e) {
    }

    Window::getInstance();
    Controller controller;
    Window::getInstance()->gameLoop(controller);
    return 0;
}

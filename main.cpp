//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/03/17.
//

#include <SFML/Graphics.hpp>

#include "Window.h"
#include "Audio.h"
#include "Fonts.h"
#include "LoadFileError.h"
#include "MessageBox.h"

int main() {
    srand((unsigned int) (time(NULL)));

    try {
        Audio::loadSounds();
        Images::loadImages();
        Fonts::loadFonts();
    }
    catch (const LoadFileError &e) {
        MessageBox mb("Error!");
        mb.showMessage(std::string(e.what()) + ": \nPath: " + e.getPath() + "\nFilename: " + e.getFilename());
        return 0;
    }

    Window::getInstance();
    Controller controller;
    Window::getInstance()->gameLoop(controller);
    return 0;
}

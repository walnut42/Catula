//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/03/17.
//

#include <SFML/Graphics.hpp>

#include "Window.h"
#include "Audio.h"
#include "Fonts.h"
#include "MessageBox.h"

int main() {
    std::srand(std::time(0));

    try {
        Audio::loadSounds();
        Images::loadImages();
        Fonts::loadFonts();
    }
    catch (const load_file_error &e) {
        MessageBox mb("Error!");
        mb.showMessage(std::string(e.what()) + ": \nPath: " + e.getPath() + "\nFilename: " + e.getFilename());
        std::exit(EXIT_FAILURE);
    }

    Window::getInstance();
    Controller controller;
    Window::getInstance()->gameLoop(controller);
    return 0;
}

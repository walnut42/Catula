//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/03/17.
//

#include <SFML/Graphics.hpp>

#include "Window.h"
#include "Audio.h"
#include "Fonts.h"
#include "MessageBox.h"
#include "BadgesManager.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

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

    BadgesManager::loadBadges();

    Window *instance = Window::getInstance();
    Controller controller;
    instance->gameLoop(controller);

    BadgesManager::destroyBadgesObservers();

    BadgesManager::saveBadges();
    return 0;
}

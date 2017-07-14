//
// Created by Lorenzo Nuti and Paolo Valcepina on 01/04/17.
//

#include "gtest/gtest.h"
#include "../MessageBox.h"
#include "../Fonts.h"
#include "../Audio.h"
#include "../BadgesManager.h"

int main(int argc, char **argv) {
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

    BadgesManager *badgesManager = BadgesManager::getInstance();
    badgesManager->loadBadges();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
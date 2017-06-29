//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/03/17.
//

#include <SFML/Graphics.hpp>

#include "Window.h"
#include "Background.h"
#include "MainCharacter.h"


int main() {
    srand((unsigned int) (time(NULL)));

    Window window("Game");
    Background background(&window);
    MainCharacter mainCharacter{&window};
    Textbox textBox{&window, &mainCharacter};
    window.gameLoop(&background, &mainCharacter);
    return 0;
}

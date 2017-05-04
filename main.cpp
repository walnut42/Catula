//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/03/17.
//

#include <SFML/Graphics.hpp>

#include "Window.h"
#include "Background.h"
#include "MainCharacter.h"


int main() {
    srand((unsigned int) (time(NULL)));

    Background::getInstance();
    MainCharacter::getInstance();
    Textbox::getInstance();
    Window::getInstance()->gameLoop();
    return 0;
}

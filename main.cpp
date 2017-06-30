//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/03/17.
//

#include <SFML/Graphics.hpp>

#include "Window.h"


int main() {
    srand((unsigned int) (time(NULL)));

    Controller controller;

    Background::getInstance();
    MainCharacter::getInstance();
    Window::getInstance()->gameLoop(controller);
    return 0;
}

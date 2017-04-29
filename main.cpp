//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/03/17.
//

#include <SFML/Graphics.hpp>

#include "Event.h"
#include "Window.h"
#include "Background.h"
#include "MainCharacter.h"


int main() {
    srand((unsigned int) (time(NULL)));

    Window *window = Window::getInstance();
    Background *background = Background::getInstance();
    MainCharacter *character = MainCharacter::getInstance();

    window->gameLoop();
    return 0;
}

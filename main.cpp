//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/03/17.
//

#include <SFML/Graphics.hpp>

#include "Event.h"
#include "Window.h"
#include "Background.h"
#include "MainCharacter.h"

//Nuova versione

int main() {
    srand((unsigned int) (time(NULL)));

    Window *window = Window::getInstance();
    Background *background = Background::getInstance();
    MainCharacter *character = MainCharacter::getInstance();

    window->updateEvent += background;
    window->updateEvent += character;
    window->drawEvent += background;
    window->drawEvent += character;

    window->gameLoop();
    return 0;
}

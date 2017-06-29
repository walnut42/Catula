//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/03/17.
//

#include <SFML/Graphics.hpp>

#include "Window.h"
#include "Background.h"
#include "MainCharacter.h"
#include "Model.h"
#include "Controller.h"


int main() {
    srand((unsigned int) (time(NULL)));

    Model model;
    Controller controller(model);
    Window window("Game", controller, model);
    //Textbox textBox{&window, &mainCharacter};
    window.gameLoop();
    return 0;
}

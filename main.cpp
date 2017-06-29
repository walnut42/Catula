//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/03/17.
//

#include <SFML/Graphics.hpp>

#include "Model.h"
#include "Controller.h"
#include "Window.h"


int main() {
    srand((unsigned int) (time(NULL)));

    Model model;
    Controller controller(model);
    Window window("Game", controller, model);
    window.gameLoop();
    return 0;
}

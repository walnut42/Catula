//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/04/17.
//

#ifndef CATULA_MESSAGEBOX_H
#define CATULA_MESSAGEBOX_H

#include <SFML/Graphics.hpp>

#include "Controller.h"
#include "Entity.h"


class MessageBox {
public:
    MessageBox(const std::string &title);

    void showMessage(const std::string &message);

private:

    void draw();

    void processInput();

    sf::RenderWindow window;
    sf::Text content;
    sf::Font font;
};


#endif //CATULA_MESSAGEBOX_H

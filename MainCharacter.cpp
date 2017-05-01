//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#include "MainCharacter.h"
#include "Window.h"

MainCharacter *MainCharacter::instance = nullptr;

MainCharacter::MainCharacter() : Entity(15, 15) {
    texture.loadFromFile("../Resources/Mushroom.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    pos.x = 10;
    pos.y = 10;
}

void MainCharacter::update() {
    MainCharacter::handleInput();
    pos.y += vel.y * Window::getInstance()->getElapsed();

    //Borders collision
    if (pos.y + size.y >= 100 - bottom) {
        vel.y = 0;
        pos.y = 100 - bottom - size.y;
    } else if (pos.y <= top) {
        vel.y = 0;
        pos.y = top;
    }
}

void MainCharacter::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        vel.y -= upg * Window::getInstance()->getElapsed();
    else
        vel.y += g * Window::getInstance()->getElapsed();
};

bool MainCharacter::collide(Entity *obj) {
    return (vehicle != nullptr && Entity::collide(vehicle, obj)) || Entity::collide(this, obj);
}

MainCharacter *MainCharacter::getInstance() {
    if (instance == nullptr) {
        instance = new MainCharacter;
    }
    return instance;
}
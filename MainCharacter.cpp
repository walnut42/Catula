//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#include "MainCharacter.h"

MainCharacter *MainCharacter::instance = nullptr;

MainCharacter::MainCharacter() : Entity(15, 15) {
    texture.loadFromFile("../Resources/Mushroom.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    pos.x = 10;
    pos.y = 10;
}

void MainCharacter::update(const sf::Time &elapsed) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        vel.y -= upg * elapsed.asSeconds();
    else
        vel.y += g * elapsed.asSeconds();

    pos.y += vel.y * elapsed.asSeconds();

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
    // TODO put Input in handleInput
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
//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#include "MainCharacter.h"

MainCharacter *MainCharacter::instance = nullptr;

MainCharacter::MainCharacter() : Entity("../Resources/Mushroom.png", 100, 100), score(0) {
}

void MainCharacter::update() {
    MainCharacter::handleInput();
    pos.y += vel.y * Window::getInstance()->getElapsed();

    //Borders collision
    if (pos.y + size.y >= Window::getHeight() - bottom) {
        vel.y = 0;
        pos.y = Window::getHeight() - bottom - size.y;
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

void MainCharacter::increaseScore(int s) {
    score += s;
    Textbox::getInstance()->add("Score: " + std::to_string(score));
}

void MainCharacter::getRelativePoints(std::vector<sf::Vector2f> &points) const {
    points.clear();
    points.push_back(sf::Vector2f(60, 0));
    points.push_back(sf::Vector2f(140, 0));
    points.push_back(sf::Vector2f(size.x, 60));
    points.push_back(sf::Vector2f(size.x, 140));
    points.push_back(sf::Vector2f(140, size.y));
    points.push_back(sf::Vector2f(60, size.y));
    points.push_back(sf::Vector2f(0, 140));
    points.push_back(sf::Vector2f(0, 60));
}

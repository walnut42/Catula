//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#include "MainCharacter.h"
#include "Window.h"


MainCharacter::MainCharacter(ModelGame &modelGame) : Entity(modelGame, "../Resources/Mushroom.png", 100, 100),
                                                     lost{false},
                                                     score{0}, lives{3} {

}


void MainCharacter::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        vel.y -= upg * Window::getInstance()->getElapsed();
    else
        vel.y += g * Window::getInstance()->getElapsed();
};

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

bool MainCharacter::collide(Entity *obj) {
    return (vehicle != nullptr && Entity::collide(vehicle, obj)) || Entity::collide(this, obj);
}

bool MainCharacter::hasLost() const {
    return lost;
}

int MainCharacter::getLives() const {
    return lives;
}

int MainCharacter::getScore() const {
    return score;
}

void MainCharacter::increaseLife(int l) {
    if (lives)
        lives += l;
    else
        lost = true;
}

void MainCharacter::increaseScore(int s) {
    if (!lost)
        score += s;
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
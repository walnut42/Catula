//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#include "MainCharacter.h"

#include "Background.h"

MainCharacter::MainCharacter(ModelGame &modelGame, Image image) : Entity{modelGame, image, 100, 100}, lost{false},
                                                                  score{0}, lives{3} {

}

void MainCharacter::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        acc.y = upg;
    else
        acc.y = g;
};

void MainCharacter::update() {
    MainCharacter::handleInput();

    updatePos();

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
    return Entity::collide(this, obj);
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
    if (l < 0)
        modelGame.getBackground()->setVel();

    lives += l;
    if (lives <= 0)
        lost = true;
}

void MainCharacter::increaseScore(int s) {
    if (!lost)
        score + s < 0 ? score = 0 : score += s;
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

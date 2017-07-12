//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#include "MainCharacter.h"

#include "Background.h"

MainCharacter::MainCharacter(ModelGame &modelGame, Image image) : Entity{modelGame, image, 100, 100}, lost{false},
                                                                  score{0}, lives{3}, lifeScore{100}, maxLives{4} {
    Audio::setSound(lifeSound, Sound::Life);
}

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
    notify(Subscription::Position);
}

bool MainCharacter::collide(Entity *obj) {
    return Entity::collide(this, obj);
}

bool MainCharacter::hasLost() const {
    return lost;
}

float MainCharacter::getDistance() {
    return modelGame.getBackground()->getDistance();
}

float MainCharacter::getVelX() {
    return -modelGame.getBackground()->getVel();
}

int MainCharacter::getLives() const {
    return lives;
}

int MainCharacter::getScore() const {
    return score;
}

void MainCharacter::increaseLives(int l) {
    if (l < 0)
        modelGame.getBackground()->setVel();
    lives = lives + l > maxLives ? maxLives : (lives + l < 0 ? 0 : lives + l);
    if (lives == 0) {
        lost = true;
    }
    notify(Subscription::Life);
}

void MainCharacter::increaseScore(int s) {
    if (!lost)
        score + s < 0 ? score = 0 : score += s;
    if (score >= lifeScore) {
        lifeScore += 100;
        increaseLives(1);
        lifeSound.play();
    }
    notify(Subscription::Score);
}

void MainCharacter::playSound(Sound name) {
    sound.stop();
    Audio::setSound(sound, name);
    if (lifeSound.getStatus() != sf::Sound::Status::Playing)
        sound.play();
}

void MainCharacter::subscribe(Subscription s, Badge *b) {
    badges.insert(std::make_pair(s, b));
}

void MainCharacter::unsubscribe(Subscription s, Badge *b) {
    auto range = badges.equal_range(s);
    for (auto i = range.first; i != range.second; ++i) {
        if (i->second == b) {
            badges.erase(i);
            break;
        }
    }
}

void MainCharacter::notify(Subscription s) {
    auto range = badges.equal_range(s);

    for (auto i = range.first; i != range.second;) {
        auto prev_i = i;
        i++;
        prev_i->second->update();
    }
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

void MainCharacter::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        acc.y = upg;
    else
        acc.y = g;
};

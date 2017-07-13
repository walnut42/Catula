//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/05/17.
//

#include "GameInfo.h"

#include <iomanip>

#include "MainCharacter.h"
#include "Window.h"
#include "Background.h"
#include "Fonts.h"
#include "BadgesManager.h"

GameInfo::GameInfo(ModelGame &modelGame) : modelGame{modelGame}, badge{nullptr}, brHeight{100}, brPadding{60} {
    Fonts::setText(content, Font::Score);
    content.setCharacterSize(35);
    content.setColor(sf::Color::Red);
    content.setPosition(100, 0);
    Images::setSprite(life, Image::Heart);
    lifePos = sf::Vector2f(Window::getWidth() - 70, 10);

    Fonts::setText(badgeText, Font::Serif);
    badgeText.setCharacterSize(25);
    badgeText.setColor(sf::Color::White);
    badgeText.setString("New badge unlocked!");

    badgeRect.setFillColor(sf::Color(0, 0, 0, 150));
    badgeRect.setSize(
            sf::Vector2f(badgeText.getLocalBounds().width + BadgesManager::getInstance()->getBadgeSize() + 60, 100));
    Audio::setSound(sound, Sound::BadgeUnlocked);
    std::cout << badgeRect.getSize().x << std::endl;
    std::cout << badgeRect.getSize().y << std::endl;
}

void GameInfo::draw() {
    Window *window = Window::getInstance();
    window->drawDrawable(content);
    for (int i = 0; i < modelGame.getMainCharacter()->getLives(); ++i) {
        window->drawSprite(life, lifePos + sf::Vector2f(-70 * i, 0));
    }

    if (badge != nullptr) {
        float time = clock.getElapsedTime().asSeconds();
        float y = 0;
        if (time <= 1)
            y = -100 + 200 * time - 100 * time * time;
        else if (time >= 3)
            y = 0 + 300 / 4 * time - 100 / 4 * time * time;

        badgeText.setPosition(window->getWidth() / 2 + 30, y + 25);
        badgeRect.setPosition(window->getWidth() / 2, y);
        window->drawDrawable(badgeRect);
        window->drawDrawable(badgeText);
        badge->drawNotify(window, window->getWidth() / 2 + badgeText.getGlobalBounds().width + brPadding, y + 10);
    }
}

void GameInfo::update() {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(0) << modelGame.getBackground()->getDistance();
    content.setString("Score: " + std::to_string(modelGame.getMainCharacter()->getScore()) +
                      "\t\tDistance: " + stream.str());
    lifePos = sf::Vector2f(Window::getWidth() - 70, 10);

    BadgesManager::getInstance()->foreachBadge([this](BadgeInfo &b) {
        if (b.updateBadge()) {
            badge = &b;
            clock.restart();
            sound.play();
        }
    });

    if (clock.getElapsedTime() > sf::seconds(4))
        badge = nullptr;
}

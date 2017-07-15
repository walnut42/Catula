//
// Created by Lorenzo Nuti and Paolo Valcepina on 04/05/17.
//

#include "GameInfo.h"

#include <iomanip>

#include "Window.h"
#include "Background.h"
#include "MainCharacter.h"
#include "BadgesManager.h"
#include "Fonts.h"

GameInfo::GameInfo(ModelGame &modelGame) : modelGame{modelGame}, badge{nullptr},
                                           notifyHeight{100}, paddingX{10}, paddingY{20} {
    Fonts::setText(content, Font::Score);
    content.setCharacterSize(35);
    content.setColor(sf::Color::Red);
    content.setPosition(100, 0);
    Images::setSprite(life, Image::Heart);
    hWidth = life.getGlobalBounds().width;

    lifePos = sf::Vector2f(Window::getWidth() - hWidth - paddingY, paddingX);

    Fonts::setText(badgeText, Font::Serif);
    badgeText.setCharacterSize(25);
    badgeText.setColor(sf::Color::White);
    badgeText.setString("New badge unlocked!");

    badgeRect.setFillColor(sf::Color(0, 0, 0, 150));
    badgeRect.setSize(sf::Vector2f(
            badgeText.getLocalBounds().width + BadgesManager::getInstance()->getBadgeSize() + 60, notifyHeight));
    Audio::setSound(sound, Sound::BadgeUnlocked);
}

void GameInfo::draw() {
    Window *window = Window::getInstance();
    window->drawDrawable(content);
    for (int i = 0; i < modelGame.getMainCharacter()->getLives(); ++i) {
        window->drawSprite(life, lifePos + sf::Vector2f((-hWidth - paddingY) * i, 0));
    }

    if (badge != nullptr) {
        float t = clock.getElapsedTime().asSeconds();
        float y = 0;
        const float v0 = 200;
        const float a = 100;
        if (t <= 1)
            y = -notifyHeight + v0 * t - a * t * t;
        else if (t >= 3) {
            y = -notifyHeight + v0 * (t - 2) - a * (t - 2) * (t - 2);
        }

        badgeText.setPosition(window->getWidth() / 2 + 30, y + 25);
        badgeRect.setPosition(window->getWidth() / 2, y);
        window->drawDrawable(badgeRect);
        window->drawDrawable(badgeText);
        badge->drawNotify(window, window->getWidth() / 2 + badgeText.getGlobalBounds().width + 60, y + 10);
    }
}

void GameInfo::update() {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(0) << modelGame.getBackground()->getDistance();
    content.setString("Score: " + std::to_string(modelGame.getMainCharacter()->getScore()) +
                      "\t\tDistance: " + stream.str());
    lifePos = sf::Vector2f(Window::getWidth() - hWidth - paddingY, paddingX);

    BadgesManager::getInstance()->foreachBadge([this](Badge &b) {
        if (b.updateLockedStatus()) {
            badge = &b;
            clock.restart();
            sound.play();
        }
    });

    if (clock.getElapsedTime() > sf::seconds(4))
        badge = nullptr;
}

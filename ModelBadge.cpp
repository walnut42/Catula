//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#include "ModelBadge.h"

#include "Window.h"
#include "Badge.h"
#include "BadgesManager.h"
#include "Fonts.h"

ModelBadge::ModelBadge() : selected{0} {
    Audio::setMusic(music, Music::BadgeMusic);
    music.setLoop(true);

    Audio::setSound(sound, Sound::Menu);

    nBadges = BadgesManager::getInstance()->nBadges();

    Images::setSprite(background, Image::BadgeBg);
    background.setPosition(0, 0);


    Fonts::setText(content, Font::Serif);
    content.setColor(sf::Color(150, 170, 230));
    content.setCharacterSize(25);
    content.setString("Your badges!\nPress esc to go back to menu.");
    sf::FloatRect textRect = content.getGlobalBounds();
    content.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    content.setPosition(Window::getWidth() / 2, 200);

    Fonts::setText(title, Font::BlackWidow);
    title.setCharacterSize(200);
    title.setColor(sf::Color::Red);
    title.setString("CATULA");
    sf::FloatRect titleRect = title.getGlobalBounds();
    title.setOrigin(titleRect.left + titleRect.width / 2.0f, titleRect.top + titleRect.height / 2.0f);
    title.setPosition(0, 100);

    Fonts::setText(badgeDescription, Font::Serif);
    badgeDescription.setColor(sf::Color::White);
    badgeDescription.setCharacterSize(25);

    Fonts::setText(badgeName, Font::Serif);
    badgeName.setColor(sf::Color::White);
    badgeName.setCharacterSize(25);

    float size = BadgesManager::getInstance()->getBadgeSize();
    selection.setSize(sf::Vector2f(size + 2 * padding, size + barHeight + 3 * padding));
    selection.setFillColor(sf::Color::Transparent);
    selection.setOutlineColor(sf::Color(150, 170, 230));
    selection.setOutlineThickness(5);
    selection.setOrigin(selection.getSize().x / 2.0f, 5);
}

ModelBadge::~ModelBadge() {

}

ModelBase *ModelBadge::processInput(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        return getModel(Controller::modelMenu);
    } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
        if (selected + 1 < nBadges)
            selected++;
        sound.play();
    } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
        if (selected - 1 >= 0)
            selected--;
        sound.play();
    }
    return nullptr;
}

ModelBase *ModelBadge::update() {
    float elapsed = clock.getElapsedTime().asSeconds();

    background.setScale(Window::getWidth() / background.getTextureRect().width,
                        Window::getHeight() / background.getTextureRect().height);

    if (elapsed < 3)
        title.setPosition(static_cast<float>(Window::getWidth() / 2.0f * (1 - exp(-2.5 * elapsed))), 100);
    else
        title.setPosition(Window::getWidth() / 2.0f, 100);

    content.setPosition(Window::getWidth() / 2.0f, 200);

    Badge &b = BadgesManager::getInstance()->getBadge(selected);
    badgeName.setString(b.getName());
    sf::FloatRect textRectName = badgeName.getGlobalBounds();
    badgeName.setOrigin(textRectName.width / 2.0f, textRectName.height / 2.0f);
    badgeName.setPosition(Window::getWidth() / 2, Window::getHeight() - 100);

    badgeDescription.setString(b.getDescription());
    sf::FloatRect textRect = badgeDescription.getGlobalBounds();
    badgeDescription.setOrigin(textRect.width / 2.0f, textRect.height / 2.0f);
    badgeDescription.setPosition(Window::getWidth() / 2, Window::getHeight() - 65);
    return nullptr;
}

void ModelBadge::draw() {
    Window *window = Window::getInstance();
    window->drawDrawable(background);
    window->drawDrawable(title);
    window->drawDrawable(content);
    window->drawDrawable(badgeDescription);
    window->drawDrawable(badgeName);
    BadgesManager *badgesManager = BadgesManager::getInstance();

    float newLine = -1;
    int i = 0;
    while (newLine < 0) {
        newLine = Window::getWidth() / 2.0f - (nBadges - i) * (badgesManager->getBadgeSize() + margin) / 2.0f;
        i++;
    }
    float x = newLine;
    float y = 300;
    float maxWidth = Window::getWidth();
    int n = 0;
    badgesManager->foreachBadge([&](Badge &b) {
        b.drawBadge(window, x, y, padding, barHeight);
        if (n == selected) {
            selection.setOrigin(padding, padding);
            selection.setPosition(x, y);
            window->drawDrawable(selection);
        }
        n++;

        x += badgesManager->getBadgeSize() + margin;
        if (x > maxWidth - badgesManager->getBadgeSize() - margin) {
            y += badgesManager->getBadgeSize() + margin;
            x = newLine;
        }
    });
}

void ModelBadge::enter() {
    music.play();
    clock.restart();
}

void ModelBadge::exit() {
    music.stop();
}

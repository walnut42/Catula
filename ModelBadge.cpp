//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#include "ModelBadge.h"

#include "Window.h"
#include "Fonts.h"
#include "BadgesManager.h"

ModelBadge::ModelBadge() {

    Images::setSprite(background, Image::BadgeBg);
    background.setPosition(0, 0);


    Fonts::setText(content, Font::Serif);
    content.setColor(sf::Color(150, 170, 230));
    content.setCharacterSize(25);
    content.setString("Your badges!");
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

}

ModelBadge::~ModelBadge() {

}

ModelBase *ModelBadge::processInput(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        return getModel(Controller::modelMenu);
    } else
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

    return nullptr;
}

void ModelBadge::draw() {
    Window::getInstance()->drawDrawable(background);
    Window::getInstance()->drawDrawable(title);
    Window::getInstance()->drawDrawable(content);

    float x = 100, y = 300;
    Window *w = Window::getInstance();
    float maxWidth = Window::getWidth();
    BadgesManager::foreachBadge([&](BadgeInfo &b) {
        b.drawBadge(w, x, y);
        x += 200;
        if (x > maxWidth - 150) {
            y += 200;
            x = 100;
        }

    });
}

void ModelBadge::enter() {
    clock.restart();
}

void ModelBadge::exit() {

}

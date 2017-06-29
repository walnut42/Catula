//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/04/17.
//

#include "Window.h"

#include "Debug.h"

Window::Window(const std::string &title, Controller &controller, const Model &model) : controller{controller} {
    windowTitle = title;
    fullscreen = false;
    closed = false;
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    create();
    textBox = new Textbox(this, model);
}

void Window::create() {
    auto style = (fullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    window.create(sf::VideoMode::getDesktopMode(), windowTitle, style);
    // Can't call getWidth here, use getProportions instead.
    window.setView(sf::View(sf::FloatRect(0, 0, getProportions(), getHeight())));
}

void Window::destroy() {
    window.close();
}


void Window::toggleFullscreen() {
    fullscreen = !fullscreen;
    destroy();
    create();
}

void Window::draw() {
    window.clear(sf::Color::Black);
    controller.draw(this);
    textBox->draw(this);
    //TODO remove debug at release time
    Debug::getInstance()->DrawText(window);
    window.display();
}

void Window::gameLoop() {
    while (!closed) {
        processInput();
        elapsed += clock.restart();
        for (int loops = 0; elapsed >= ms_per_update && loops < max_loops; loops++) {
            controller.update(ms_per_update.asSeconds());
            textBox->update();
            elapsed -= ms_per_update;
        }
        draw();
    }
}


void Window::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            closed = true;
            destroy();
        } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F11) {
            toggleFullscreen();
        } else if (event.type == sf::Event::Resized) {
            window.setView(sf::View(sf::FloatRect(0, 0, getProportions(), getHeight())));
        } else
            controller.processInput(event);
    }
}

void Window::drawSprite(sf::Sprite &sprite, const sf::Vector2f &pos, const sf::Vector2f &vel, float angle,
                        float angleVel) {
    sprite.setPosition(pos + vel * elapsed.asSeconds());
    sprite.setRotation(angle + angleVel * elapsed.asSeconds());
    window.draw(sprite);
}

void Window::drawEntity(Entity &entity) {
    drawSprite(entity.getSprite(), entity.getPos(), entity.getVel(), entity.getAngle(), entity.getAngleVel());
}

void Window::drawDrawable(sf::Drawable &drawable) {
    window.draw(drawable);
}


float Window::getProportions() {
    sf::Vector2u size = window.getSize();
    return getHeight() * size.x / size.y;
}

Window::~Window() {
    delete textBox;
}

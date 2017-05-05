//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/04/17.
//

#include "Window.h"

#include "Debug.h"
#include "CollidableManager.h"

Window *Window::instance = nullptr;

Window::Window() {
    setup("Catula");
}

void Window::setup(const std::string &title) {
    windowTitle = title;
    isFullscreen = false;
    isDone = false;
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    create();
}

void Window::create() {
    auto style = (isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    window.create(sf::VideoMode::getDesktopMode(), windowTitle, style);
    //Can't call getWidth here, use getProportions instead.
    window.setView(sf::View(sf::FloatRect(0, 0, getProportions(), getHeight())));
}

void Window::destroy() {
    window.close();
}

void Window::update() {
    notifyUpdate();
}

void Window::toggleFullscreen() {
    isFullscreen = !isFullscreen;
    destroy();
    create();
}

void Window::draw() {
    window.clear(sf::Color::Black);
    notifyDraw();
    Debug::getInstance()->DrawText(window);
    window.display();
}

void Window::gameLoop() {
    while (!isDone) {
        processInput();
        elapsed += clock.restart();

        for (int loops = 0; elapsed >= ms_per_update && loops < max_loops; loops++) {
            update();
            CollidableManager::update();
            elapsed -= ms_per_update;
        }

        draw();
    }
}


void Window::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            isDone = true;
            destroy();
        } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F11) {
            toggleFullscreen();
        } else if (event.type == sf::Event::Resized) {
            window.setView(sf::View(sf::FloatRect(0, 0, getProportions(), getHeight())));
        }
    }
}


void Window::drawSprite(sf::Sprite &sprite, sf::Vector2f pos, sf::Vector2f vel) {
    pos.x = pos.x + vel.x * elapsed.asSeconds();
    pos.y = pos.y + vel.y * elapsed.asSeconds();
    sprite.setPosition(pos);
    window.draw(sprite);
}

void Window::drawEntity(Entity &entity) {
    drawSprite(entity.getSprite(), entity.getPos(), entity.getVel());
}

void Window::drawDrawable(sf::Drawable &drawable) {
    window.draw(drawable);
}

Window *Window::getInstance() {
    if (instance == nullptr) {
        instance = new Window;
    }
    return instance;
}
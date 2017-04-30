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

bool Window::IsFullscreen() {
    return isFullscreen;
}

void Window::draw() {
    window.clear(sf::Color::Black);
    notifyDraw();
    Debug::getInstance()->DrawText(window);
    window.display();
}

void Window::gameLoop() {
    while (!isDone) {
        processInput(window);
        elapsed += clock.restart();

        int loops = 0;
        while (elapsed >= ms_per_update && loops < max_loops) {
            update();
            CollidableManager::update();
            elapsed -= ms_per_update;
            loops++;
        }

        draw();
    }
}


void Window::processInput(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            isDone = true;
            destroy();
        } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F11) {
            toggleFullscreen();
        } else if (event.type == sf::Event::Resized) {
            window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
        }
    }
}


void Window::drawSprite(sf::Sprite &sprite, sf::Vector2f size, sf::Vector2f pos, sf::Vector2f vel) {
    size = resizeVector(size);
    sf::Vector2u oldSize = sprite.getTexture()->getSize();
    sprite.setScale(size.x / oldSize.x, size.y / oldSize.y);
    pos.x = pos.x + vel.x * elapsed.asSeconds();
    pos.y = pos.y + vel.y * elapsed.asSeconds();
    sprite.setPosition(resizeVector(pos));
    window.draw(sprite);
}

void Window::drawEntity(Entity &entity) {
    drawSprite(entity.getSprite(), entity.getSize(), entity.getPos(), entity.getVel());
}

sf::Vector2f Window::resizeVector(const sf::Vector2f v) const {
    sf::Vector2f r;
    r.y = v.y * window.getSize().y / 100;
    r.x = v.x * window.getSize().y / 100;
    return r;
}

float Window::getWidth() const {
    return static_cast<float>(window.getSize().x) / window.getSize().y * 100;
}

Window *Window::getInstance() {
    if (instance == nullptr) {
        instance = new Window;
    }
    return instance;
}
//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/04/17.
//

#include "Window.h"

#include "Debug.h"

Window *Window::instance = nullptr;

Window::Window() : windowTitle{"Catula"}, isFullscreen{false}, isDone{false} {
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    create();
}

void Window::create() {
    auto style = (isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    window.create(sf::VideoMode::getDesktopMode(), windowTitle, style);
    // Can't call getWidth here, use getProportions instead.
    window.setView(sf::View(sf::FloatRect(0, 0, getProportions(), getHeight())));
}

void Window::toggleFullscreen() {
    isFullscreen = !isFullscreen;
    window.close();
    create();
}

void Window::draw(Controller &controller) {
    window.clear(sf::Color::Black);
    controller.draw();
    Debug::getInstance()->DrawText(window);
    window.display();
}

void Window::gameLoop(Controller &controller) {
    while (!isDone) {
        processInput(controller);
        elapsed += clock.restart();

        for (int loops = 0; elapsed >= ms_per_update && loops < max_loops; loops++) {
            controller.update();
            elapsed -= ms_per_update;
        }

        draw(controller);
    }
}

void Window::processInput(Controller &controller) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            isDone = true;
            window.close();
        } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F11) {
            toggleFullscreen();
        } else if (event.type == sf::Event::Resized) {
            window.setView(sf::View(sf::FloatRect(0, 0, getProportions(), getHeight())));
        } else
            controller.processInput(event);
    }
}

void
Window::drawSprite(sf::Sprite &sprite, const sf::Vector2f &pos, const sf::Vector2f &vel, float angle, float angleVel) {
    if (drawPrevision) {
        sprite.setPosition(pos + vel * elapsed.asSeconds());
        sprite.setRotation(angle + angleVel * elapsed.asSeconds());
    } else {
        sprite.setPosition(pos);
        sprite.setRotation(angle);
    }

    window.draw(sprite);
}

void Window::drawEntity(Entity &entity) {
    drawSprite(entity.getSprite(), entity.getPos(), entity.getVel(), entity.getAngle(), entity.getAngleVel());
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

void Window::setDrawPrevision(bool drawPrevision) {
    Window::drawPrevision = drawPrevision;
}

float Window::getWidth() {
    if (instance != nullptr) {
        sf::Vector2u size = instance->window.getSize();
        return getHeight() * size.x / size.y;
    }
    return 0;
}

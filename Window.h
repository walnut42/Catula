//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/04/17.
//

#ifndef CATULA_WINDOW_H
#define CATULA_WINDOW_H

#include <SFML/Graphics.hpp>

#include "Drawable.h"
#include "DrawableSubject.h"
#include "Entity.h"
#include "Textbox.h"


class Window : public DrawableSubject {
public:
    static Window *getInstance();

    void gameLoop();

    void drawSprite(sf::Sprite &sprite, const sf::Vector2f &pos, const sf::Vector2f &vel, float angle = 0,
                    float angleVel = 0);

    void drawEntity(Entity &entity);

    void drawDrawable(sf::Drawable &drawable);

    float getElapsed() const {
        return ms_per_update.asSeconds();
    }

    float getScale() const {
        return getHeight() / window.getSize().y;
    }

    static float getWidth() {
        if (instance != nullptr) {
            sf::Vector2u size = instance->window.getSize();
            return getHeight() * size.x / size.y;
        }
        return 0;
    }

    static float getHeight() {
        return 1000;
    }

private:
    Window();

    static Window *instance;

    float getProportions() {
        sf::Vector2u size = window.getSize();
        return getHeight() * size.x / size.y;
    }

    void toggleFullscreen();

    void update();

    void draw();

    void processInput();

    void setup(const std::string &title);

    void destroy();

    void create();

    sf::RenderWindow window;
    std::string windowTitle;
    bool isFullscreen;
    bool isDone;
    const sf::Time ms_per_update = sf::milliseconds(7);
    const int max_loops = 5;
    sf::Clock clock;
    sf::Time elapsed;
};


#endif //CATULA_WINDOW_H

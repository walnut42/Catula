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
#include "Background.h"
#include "Textbox.h"
#include "Controller.h"


class Background;

class MainCharacter;

class Controller;

class Window {
public:
    Window(const std::string &title, Controller &controller, const Model &model);

    ~Window();

    void gameLoop();

    void drawSprite(sf::Sprite &sprite, const sf::Vector2f &pos, const sf::Vector2f &vel, float angle = 0,
                    float angleVel = 0);

    void drawEntity(Entity &entity);

    void drawDrawable(sf::Drawable &drawable);

    float getScale() const {
        return getHeight() / window.getSize().y;
    }

    float getWidth() {
        sf::Vector2u size = window.getSize();
        return getHeight() * size.x / size.y;
    }

    float getHeight() const {
        return 1000;
    }

private:
    float getProportions();

    void toggleFullscreen();

    void draw();

    void processInput();

    void destroy();

    void create();

    sf::RenderWindow window;
    std::string windowTitle;
    bool fullscreen;
    bool closed;
    const sf::Time ms_per_update = sf::milliseconds(7);
    const int max_loops = 5;
    sf::Clock clock;
    sf::Time elapsed;

    Controller &controller;

    Textbox *textBox;
};


#endif //CATULA_WINDOW_H

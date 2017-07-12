//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/04/17.
//

#ifndef CATULA_WINDOW_H
#define CATULA_WINDOW_H

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Controller.h"


class Window {
public:
    static Window *getInstance();

    void gameLoop(Controller &controller);

    void drawSprite(sf::Sprite &sprite, const sf::Vector2f &pos, const sf::Vector2f &vel = sf::Vector2f(),
                    float angle = 0, float angleVel = 0);

    void drawEntity(Entity &entity);

    void drawDrawable(sf::Drawable &drawable);

    float getElapsed() const {
        return ms_per_update.asSeconds();
    }

    static float getWidth();

    static float getHeight() {
        return 1000;
    }

    void setDrawPrevision(bool drawPrevision);

private:
    Window();

    static Window *instance;

    float getProportions() {
        sf::Vector2u size = window.getSize();
        return getHeight() * size.x / size.y;
    }

    void toggleFullscreen();

    void draw(Controller &controller);

    void processInput(Controller &controller);

    void create();

    sf::RenderWindow window;
    std::string windowTitle;
    bool isFullscreen;
    bool isDone;
    const sf::Time ms_per_update = sf::milliseconds(7);
    const int max_loops = 5;
    sf::Clock clock;
    sf::Time elapsed;
    bool drawPrevision = true;
};


#endif //CATULA_WINDOW_H

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

    void drawSprite(sf::Sprite &sprite, sf::Vector2f size, sf::Vector2f pos, sf::Vector2f vel);

    void drawEntity(Entity &entity);

    void drawDrawable(sf::Drawable &drawable);

    float getProportions() const;

    float getElapsed() const {
        return ms_per_update.asSeconds();
    }

    sf::Vector2f resizeVector(const sf::Vector2f v) const;

private:
    Window();

    static Window *instance;

    void toggleFullscreen();

    void update();

    void draw();

    void processInput(sf::RenderWindow &window);

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

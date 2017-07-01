//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#ifndef CATULA_MAINCHARACTER_H
#define CATULA_MAINCHARACTER_H


#include <iostream>

#include "Entity.h"
#include "Textbox.h"
#include "Vehicle.h"

class ModelGame;

class MainCharacter : public Entity {
public:
    MainCharacter(ModelGame &modelGame);

    void handleInput();

    virtual void update() override;

    bool collide(Entity *obj);

    bool hasLost() const;

    int getLives() const;

    int getScore() const;

    void increaseLife(int l);

    void increaseScore(int s);

protected:
    virtual void getRelativePoints(std::vector<sf::Vector2f> &points) const override;

private:
    Vehicle *vehicle = nullptr;
    const float g = 980;
    const float upg = 1000;
    const float top = 0;
    const float bottom = 0;
    bool lost;
    int lives;
    int score;
};


#endif //CATULA_MAINCHARACTER_H

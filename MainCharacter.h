//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#ifndef CATULA_MAINCHARACTER_H
#define CATULA_MAINCHARACTER_H

#include <iostream>

#include "Entity.h"
#include "Vehicle.h"
#include "Textbox.h"

class MainCharacter : public Entity {
public:
    static MainCharacter *getInstance();

    void handleInput();

    virtual void update() override;

    bool collide(Entity *obj);

    void increaseScore();

protected:
    virtual void getRelativePoints(std::vector<sf::Vector2f> &points) const override;
private:
    MainCharacter();

    static MainCharacter *instance;
    Vehicle *vehicle = nullptr;

    const float g = 980;
    const float upg = 1000;
    const float top = 0;
    const float bottom = 0;

    int score;
};


#endif //CATULA_MAINCHARACTER_H

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

private:
    MainCharacter();

    static MainCharacter *instance;
    sf::Texture texture;
    Vehicle *vehicle = nullptr;

    const float g = 98;
    const float upg = 100;
    const float top = 0;
    const float bottom = 0;

    int score;
    Textbox *log;
};


#endif //CATULA_MAINCHARACTER_H

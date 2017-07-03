//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#ifndef CATULA_MAINCHARACTER_H
#define CATULA_MAINCHARACTER_H


#include <iostream>

#include "Entity.h"
#include "Textbox.h"
#include "Vehicle.h"
#include "Audio.h"

class ModelGame;

class MainCharacter : public Entity {
public:
    MainCharacter(ModelGame &modelGame, Image image);

    void handleInput();

    virtual void update() override;

    bool collide(Entity *obj);

    void playSound(Sound name) {
        sound.stop();
        Audio::setSound(sound, name);
        sound.play();
    }

protected:
    virtual void getRelativePoints(std::vector<sf::Vector2f> &points) const override;

private:
    Vehicle *vehicle = nullptr;
    const float g = 980;
    const float upg = 1000;
    const float top = 0;
    const float bottom = 0;

    sf::Sound sound;
};


#endif //CATULA_MAINCHARACTER_H

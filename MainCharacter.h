//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#ifndef CATULA_MAINCHARACTER_H
#define CATULA_MAINCHARACTER_H

#include <iostream>

#include "Audio.h"
#include "Entity.h"
#include "GameInfo.h"
#include "Badge.h"


class ModelGame;

class Badge;

enum class Score {
    Star = 1,
    Skull = 5,
    Rocket = -5
};

enum class Subscription {
    Life, Position, Score
};

class MainCharacter : public Entity {
public:
    MainCharacter(ModelGame &modelGame, Image image);

    virtual void update() override;

    bool collide(Entity *obj);

    bool hasLost() const;

    float getDistance();

    float getVelX();

    int getLives() const;

    int getScore() const;

    void increaseLives(int l);

    void increaseScore(int s);

    void playSound(Sound name);

    void subscribe(Subscription s, Badge *b);

    void unsubscribe(Subscription s, Badge *b);

    void notify(Subscription s);

protected:
    virtual void getRelativePoints(std::vector<sf::Vector2f> &points) const override;

private:
    void handleInput();

    const float g = 980;
    const float upg = -1000;
    const float top = 0;
    const float bottom = 0;

    bool lost;
    int lives;
    int score;
    int lifeScore;
    int maxLives;

    sf::Sound sound;
    sf::Sound lifeSound;

    std::multimap<Subscription, Badge *> badges;
};


#endif //CATULA_MAINCHARACTER_H

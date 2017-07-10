//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#ifndef CATULA_MAINCHARACTER_H
#define CATULA_MAINCHARACTER_H

#include <iostream>

#include "Entity.h"
#include "GameInfo.h"
#include "Audio.h"
#include "Badge.h"

class Badge;

class ModelGame;

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

    void handleInput();

    virtual void update() override;

    bool collide(Entity *obj);

    bool hasLost() const;

    int getLives() const;

    int getScore() const;

    void increaseLives(int l);

    float getDistance();

    void increaseScore(int s);

    void playSound(Sound name) {
        sound.stop();
        Audio::setSound(sound, name);
        if (lifeSound.getStatus() != sf::Sound::Status::Playing)
            sound.play();
    }

    void subscribe(Subscription s, Badge *b);

    void unsubscribe(Subscription s, Badge *b);

    void notify(Subscription s);

protected:
    virtual void getRelativePoints(std::vector<sf::Vector2f> &points) const override;

private:
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

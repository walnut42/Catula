//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/06/17.
//

#ifndef CATULA_MODELGAME_H
#define CATULA_MODELGAME_H

#include <list>

#include "ModelBase.h"
#include "Images.h"

class Background;

class MainCharacter;

class Collidable;

class Textbox;

class ModelGame : public ModelBase {
public:
    ModelGame();

    explicit ModelGame(Image image);

    ~ModelGame();

    virtual ModelBase *processInput(const sf::Event &event) override;

    virtual ModelBase *update() override;

    virtual void draw() override;

    virtual void enter() override;

    virtual void exit() override;

    bool hasLost() const;

    int getLives() const;

    int getScore() const;

    void increaseLife(int l);

    void increaseScore(int s);

    Background *getBackground();

    MainCharacter *getMainCharacter();

private:
    void removeCollidables();

    Background *background;
    MainCharacter *mainCharacter;
    std::list<std::unique_ptr<Collidable>> collidables;
    Textbox *textbox;

    sf::Music music;

    bool lost;
    int lives;
    int score;
};


#endif //CATULA_MODELGAME_H

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

class GameInfo;

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

    Background *getBackground();

    MainCharacter *getMainCharacter();

private:
    void removeCollidables();

    Background *background;
    MainCharacter *mainCharacter;
    std::list<std::unique_ptr<Collidable>> collidables;
    GameInfo *textbox;

    sf::Music music;
};


#endif //CATULA_MODELGAME_H

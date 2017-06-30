//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/06/17.
//

#ifndef CATULA_MODELGAME_H
#define CATULA_MODELGAME_H

#include <list>

#include "ModelBase.h"

class Background;

class MainCharacter;

class Collidable;

class Textbox;
class ModelGame : public ModelBase {
public:
    ModelGame();

    ~ModelGame();

    virtual ModelBase *processInput(const sf::Event &event) override;

    virtual ModelBase *update() override;

    virtual void draw() override;

    Background *getBackground();

    MainCharacter *getMainCharacter();

    const std::list<Collidable *> &getCollidables() const;


private:
    void removeCollidables();

    Background *background;
    MainCharacter *mainCharacter;
    std::list<Collidable *> collidables;
    Textbox *textbox;
};


#endif //CATULA_MODELGAME_H

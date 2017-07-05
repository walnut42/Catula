//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/04/17.
//

#ifndef CATULA_EVENT_H
#define CATULA_EVENT_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


class ModelBase {
public:
    virtual ModelBase *processInput(const sf::Event &event)=0;

    virtual ModelBase *update()=0;

    virtual void draw()=0;

    virtual void enter()=0;

    virtual void exit()=0;
};


#endif //CATULA_EVENT_H

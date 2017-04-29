//
// Created by Lorenzo Nuti and Paolo Valcepina on 15/04/17.
//

#ifndef CATULA_DRAWABLE_H
#define CATULA_DRAWABLE_H

#include <SFML/Graphics.hpp>

class Window;

class Drawable {
public:
    virtual void update()=0;

    virtual void draw()=0;

    virtual ~Drawable() {};
protected:
    Window *window;
};

#endif //CATULA_DRAWABLE_H

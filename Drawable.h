//
// Created by Lorenzo Nuti and Paolo Valcepina on 15/04/17.
//

#ifndef CATULA_DRAWABLE_H
#define CATULA_DRAWABLE_H


class Window;

class Drawable {
public:
    virtual ~Drawable() {};

    virtual void update(float elapsed)=0;

    virtual void draw(Window *window)=0;
};

#endif //CATULA_DRAWABLE_H

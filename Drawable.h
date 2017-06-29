//
// Created by Lorenzo Nuti and Paolo Valcepina on 15/04/17.
//

#ifndef CATULA_DRAWABLE_H
#define CATULA_DRAWABLE_H


class Window;

class Drawable {
public:
    Drawable(Window *window);

    virtual ~Drawable();

    virtual void update()=0;

    virtual void draw()=0;

protected:
    Window *window;
};

#endif //CATULA_DRAWABLE_H

//
// Created by Lorenzo Nuti and Paolo Valcepina on 13/04/17.
//

#ifndef CATULA_EVENT_H
#define CATULA_EVENT_H

#include <list>
#include "Drawable.h"

class Drawable;

class DrawableSubject {
public:
    virtual void add(Drawable *object);

    virtual void remove(Drawable *object);

    virtual void notifyUpdate() const;

    virtual void notifyDraw() const;

    virtual void operator+=(Drawable *object);

    virtual void operator-=(Drawable *object);

protected:
    virtual ~DrawableSubject() {};
private:
    std::list<Drawable *> observers;
};


#endif //CATULA_EVENT_H

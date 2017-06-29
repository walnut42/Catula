//
// Created by Lorenzo Nuti and Paolo Valcepina on 29/04/17.
//

#include "Drawable.h"

#include "Window.h"

Drawable::Drawable(Window *window) : window{window} {
    window->add(this);
}

Drawable::~Drawable() {
    window->remove(this);
}

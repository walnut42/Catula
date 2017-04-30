//
// Created by Lorenzo Nuti and Paolo Valcepina on 29/04/17.
//

#include "Drawable.h"

#include "Window.h"

Drawable::Drawable() {
    Window::getInstance()->add(this);
}

Drawable::~Drawable() {
    Window::getInstance()->remove(this);
}

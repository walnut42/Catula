//
// Created by lorenzo on 29/04/17.
//
#include "Event.h"

void DrawableSubject::add(Drawable *object) {
    observers.push_back(object);
}

void DrawableSubject::remove(Drawable *object) {
    observers.remove(object);
}

void DrawableSubject::notifyUpdate() const {
    for (auto it = observers.begin(), end = observers.end(); it != end; it++) {
        (*it)->update();
    }
}

void DrawableSubject::notifyDraw() const {
    for (auto it = observers.begin(), end = observers.end(); it != end; it++) {
        (*it)->draw();
    }
}

void DrawableSubject::operator+=(Drawable *object) {
    add(object);
}

void DrawableSubject::operator-=(Drawable *object) {
    remove(object);
}
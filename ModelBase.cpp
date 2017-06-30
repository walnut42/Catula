//
// Created by Lorenzo Nuti and Paolo Valcepina on 29/04/17.
//

#include "ModelBase.h"

void ModelBase::add(Drawable *object) {
    observers.push_back(object);
}

void ModelBase::remove(Drawable *object) {
    observers.remove(object);
}

void ModelBase::notifyUpdate() const {
    for (auto it = observers.begin(), end = observers.end(); it != end; it++) {
        (*it)->update();
    }
}

void ModelBase::notifyDraw() const {
    for (auto it = observers.begin(), end = observers.end(); it != end; it++) {
        (*it)->draw();
    }
}

void ModelBase::operator+=(Drawable *object) {
    add(object);
}

void ModelBase::operator-=(Drawable *object) {
    remove(object);
}
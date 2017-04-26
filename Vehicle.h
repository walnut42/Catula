//
// Created by Lorenzo Nuti and Paolo Valcepina on 16/03/17.
//

#ifndef CATULA_VEHICLE_H
#define CATULA_VEHICLE_H

#include <iostream>

#include "Entity.h"


class Vehicle : public Entity {
public:
    Vehicle(float width, float height) : Entity(width, height) {};
    std::string name;
};


#endif //CATULA_VEHICLE_H
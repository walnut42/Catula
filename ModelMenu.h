//
// Created by Lorenzo Nuti and Paolo Valcepina on 30/06/17.
//

#ifndef CATULA_MODELMENU_H
#define CATULA_MODELMENU_H


#include "ModelBase.h"

class ModelMenu : public ModelBase {
public:
    ModelMenu() {};

    ~ModelMenu() {};

    void processInput(const sf::Event &event) override {};
};


#endif //CATULA_MODELMENU_H

//
// Created by Lorenzo Nuti and Paolo Valcepina on 26/03/17.
//

#ifndef CATULA_OBSTACLES_H
#define CATULA_OBSTACLES_H

#include <SFML/Graphics.hpp>
#include "ModelBase.h"
#include "ModelMenu.h"
#include "ModelGame.h"
#include "ModelPause.h"
#include "ModelGameOver.h"

class Controller {
public:
    Controller();

    void processInput(const sf::Event &event);

    void update();

    void draw();

    static std::unique_ptr<ModelMenu> modelMenu;
    static std::unique_ptr<ModelGame> modelGame;
    static std::unique_ptr<ModelPause> modelPause;
    static std::unique_ptr<ModelGameOver> modelGameOver;


private:
    ModelBase *activeModel;

    void changeModel(ModelBase *newModel);
};

/**
 * Deletes old model and creates a new one passing args to his constructor
 * @param model
 * @param args
 * @return returns a raw pointer to the new model
 */
template<typename T, typename... Args>
ModelBase *newModel(std::unique_ptr<T> &model, Args... args) {
    model.reset(new T(args...));
    return model.get();
}

/**
 * Gets current model if it exists, otherwise creates a new model passing args to his constructor
 * @param model
 * @param args
 * @return returns a raw pointer to the model
 */
template<typename T, typename... Args>
ModelBase *getModel(std::unique_ptr<T> &model, Args... args) {
    if (!model)
        model.reset(new T(args...));
    return model.get();
}

#endif //CATULA_OBSTACLES_H

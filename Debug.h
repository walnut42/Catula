//
// Created by Lorenzo Nuti and Paolo Valcepina on 31/03/17.
//

#ifndef CATULA_DEBUG_H
#define CATULA_DEBUG_H

#include <SFML/Graphics.hpp>

class Debug {
public:
    static Debug *getInstance();

    // Call this function to add a variable for the debug: e.g. debug.setVar("pos", pos);
    template<typename T>
    void setVar(std::string name, T var) {
        debug[name] = std::to_string(var);
    }

    void DrawText(sf::RenderWindow &window);

    void setSpeed(sf::Time &elapsed);

private:
    Debug();

    static Debug *instance;

    // Update time of variables: high values, more readable; low values, more precision.
    // interval = 0  change value at each frame.
    const float interval = 0;

    // Simulate a slower (<1) or faster (>1) pace
    const float speed = 1;

    sf::Font font;
    std::map<std::string, std::string> debug;
    sf::Text text;
    sf::Clock clock;
};

#endif //CATULA_DEBUG_H
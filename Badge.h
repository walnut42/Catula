//
// Created by Lorenzo Nuti and Paolo Valcepina on 07/07/17.
//

#ifndef CATULA_BADGE_H
#define CATULA_BADGE_H

#include <string>

#include <SFML/Graphics.hpp>

class MainCharacter;

enum class Subscription;

class Window;

class Badge {
public:
    Badge(const std::string &className, const std::string &name, const std::string &description, float goal,
          bool memorize);

    virtual ~Badge();

    void load(std::fstream &stream);

    void save(std::fstream &stream);

    bool updateLockedStatus();

    void drawBadge(Window *window, float x, float y, int padding, int barHeight);

    void drawNotify(Window *window, float x, float y);

    void setTexture(const std::string &path);

    const std::string &getClassName() const;

    const std::string getDescription() const;

    const std::string &getName() const;

    virtual void update();

    bool isLocked() const;

    float getProgress() const;

    void addObserver(MainCharacter *mC);

    virtual void detach()=0;

protected:
    virtual void attach()=0;

    void unlock();

    float points;
    MainCharacter *mainCharacter;
private:
    bool locked;
    float goalPoints;
    bool memorize;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Sprite bar;
    sf::Sprite barEmpty;
    const std::string className;
    const std::string name;
    const std::string description;
};


#endif //CATULA_BADGE_H

//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#ifndef CATULA_BADGEINFO_H
#define CATULA_BADGEINFO_H

#include "Window.h"
#include "MainCharacter.h"
#include "Badge.h"
#include "Tools.h"


class BadgeInfo {
public:
    BadgeInfo(const std::string &className, const std::string &name, const std::string &description);

    ~BadgeInfo();

    virtual void createBadge(MainCharacter *mC)=0;

    void destroyBadge();

    void loadBadge(std::fstream &stream);

    void saveBadge(std::fstream &stream);

    bool updateBadge();

    void drawBadge(Window *window, float x, float y, int padding, int barHeight);

    void drawNotify(Window *window, float x, float y);

    void setTexture(sf::Texture &t);

    const std::string &getClassName() const;

    const std::string getDescription() const;

protected:
    bool locked;
    float progress;
    Badge *ptr;

    sf::Texture texture;
    sf::Sprite sprite;
    sf::Sprite bar;
    sf::Sprite barEmpty;
    const std::string className;
    const std::string name;
    const std::string description;
};

template<typename T>
class BadgeInfoT : public BadgeInfo {
public:
    BadgeInfoT(const std::string &className, const std::string &name, const std::string &description, float goal)
            : BadgeInfo{className, name, description}, goalPoints{goal} {

    }

    virtual void createBadge(MainCharacter *mC) {
        if (locked)
            ptr = new T(mC, goalPoints, progress);
    }

private:
    float goalPoints;
};


#endif //CATULA_BADGEINFO_H

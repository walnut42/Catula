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
    BadgeInfo(const std::string &className, const std::string &name, const std::string &description, bool memorize);

    ~BadgeInfo();

    virtual void createBadge(MainCharacter *mC)=0;

    void destroyBadge();

    void loadBadge(std::fstream &stream);

    void saveBadge(std::fstream &stream);

    bool updateBadge();

    void drawBadge(Window *window, float x, float y, int padding, int barHeight);

    void drawNotify(Window *window, float x, float y);

    void setTexture(const std::string &path);

    const std::string &getClassName() const;

    const std::string getDescription() const;

    const std::string &getName() const;

protected:
    bool locked;
    float progress;
    bool memorize;
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
    BadgeInfoT(const std::string &className, const std::string &name, const std::string &description, float goal,
               bool memorize) : BadgeInfo{className, name, description, memorize}, goalPoints{goal} {

    }

    virtual void createBadge(MainCharacter *mC) {
        if (locked)
            ptr = new T(mC, goalPoints, memorize, progress);
    }

private:
    float goalPoints;
};


#endif //CATULA_BADGEINFO_H

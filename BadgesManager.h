//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#ifndef CATULA_BADGESMANAGER_H
#define CATULA_BADGESMANAGER_H

#include <iostream>
#include <typeinfo>
#include <functional>
#include "Badge.h"
#include "MainCharacter.h"


class BadgesManager {
public:
    static BadgesManager *getInstance();

    void loadBadges();

    void saveBadges();

    void createBadgesObservers(MainCharacter *mC);

    void destroyBadgesObservers();

    void foreachBadge(std::function<void(Badge&)> lambda);

    Badge &getBadge(int i);

    const int numberOfBadges();

    const int getBadgeSize() const;

private:
    BadgesManager();

    const int badgeSize;

    const std::string filename;

    bool created;
    std::vector<std::unique_ptr<Badge>> badges;
};


#endif //CATULA_BADGESMANAGER_H

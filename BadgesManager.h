//
// Created by lorenzo on 07/07/17.
//

#ifndef CATULA_BADGESMANAGER_H
#define CATULA_BADGESMANAGER_H

#include <SFML/Graphics.hpp>
#include <fstream>

#include "Badge.h"
#include "MainCharacter.h"
#include "BadgeInfo.h"


class BadgesManager {
public:
    static void loadBadges();

    static void saveBadges();

    static void createBadgesObservers(MainCharacter *mC);

    static void destroyBadgesObservers();

private:
    BadgesManager() = delete;

    static const std::string filename;
    static std::map<std::string, BadgeInfo> badges;
};


#endif //CATULA_BADGESMANAGER_H

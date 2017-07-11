//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#include <iostream>
#include <typeinfo>
#include <functional>
#include "BadgesManager.h"
#include "BadgeDeath.h"
#include "BadgeDistance.h"
#include "BadgeFly.h"
#include "BadgeObstacle.h"
#include "BadgeScore.h"
#include "BadgeSkull.h"
#include "BadgeStarSkull.h"
#include "BadgeSpeed.h"

BadgesManager *BadgesManager::instance = nullptr;

BadgesManager::BadgesManager() : badgeSize{150}, filename{"../Resources/Saves/badges.dat"}, created{false} {
    badges.emplace_back(new BadgeInfoT<BadgeDeath>("BadgeDeath", "5 lost lives"));
    badges.emplace_back(new BadgeInfoT<BadgeDistance>("BadgeDistance", "100 distance points"));
    badges.emplace_back(new BadgeInfoT<BadgeFly>("BadgeFly", "100 distance points on the top"));
    badges.emplace_back(new BadgeInfoT<BadgeObstacle>("BadgeObstacle", "10 positive objects in a row"));
    badges.emplace_back(new BadgeInfoT<BadgeScore>("BadgeScore", "20 total points"));
    badges.emplace_back(new BadgeInfoT<BadgeSkull>("BadgeSkull", "5 skulls"));
    badges.emplace_back(new BadgeInfoT<BadgeSpeed>("BadgeSpeed", "1000 speed points"));
    badges.emplace_back(new BadgeInfoT<BadgeStarSkull>("BadgeStarSkull", "5 stars and skulls"));
}

void BadgesManager::loadBadges() {
    std::fstream stream;
    stream.open(filename, std::ios::binary | std::ios::in);
    if (stream.is_open()) {
        //n: number of badges
        int n;
        readBinary(stream, n);
        for (; n != 0; --n) {
            //s: length of name
            int s;
            readBinary(stream, s);
            std::string name;
            for (; s != 0; --s) {
                char c;
                readBinary(stream, c);
                name += c;
            }

            auto element = std::find_if(badges.begin(), badges.end(), [&name](std::unique_ptr<BadgeInfo> &ptr) {
                return ptr->getClassName() == name;
            });
            if (element != badges.end())
                (*element)->loadBadge(stream);
        }
    }

    //Load images
    const std::string path = "../Resources/Images/Badges/";
    for (auto &badge:badges) {
        sf::Texture t;
        t.loadFromFile(path + 'b' + badge->getClassName().substr(1) + ".png");
        t.setSmooth(true);
        badge->setTexture(t);
    }
}

void BadgesManager::saveBadges() {
    std::fstream stream;
    stream.open(filename, std::ios::binary | std::ios::out);
    if (stream.is_open()) {
        //n: number of badges
        int n = static_cast<int>(badges.size());
        writeBinary(stream, n);

        for (auto &badge:badges) {
            //s: length of name
            int s = static_cast<int>(badge->getClassName().length());
            writeBinary(stream, s);
            std::string name = badge->getClassName();
            for (int i = 0; i != s; i++) {
                writeBinary(stream, name[i]);
            }
            badge->saveBadge(stream);
        }
    }
}

void BadgesManager::createBadgesObservers(MainCharacter *mC) {
    created = true;
    for (auto &badge:badges)
        badge->createBadge(mC);
}

void BadgesManager::destroyBadgesObservers() {
    if (created) {
        for (auto &badge:badges)
            badge->destroyBadge();
        created = false;
    }
}

void BadgesManager::foreachBadge(std::function<void(BadgeInfo &)> lambda) {
    for (auto &badge:badges)
        lambda(*badge);
}

const int BadgesManager::numberOfBadges() {
    return static_cast<int>(badges.size());
}


BadgesManager *BadgesManager::getInstance() {
    if (instance == nullptr) {
        instance = new BadgesManager;
    }
    return instance;
}

const int BadgesManager::getBadgeSize() const {
    return badgeSize;
}

BadgeInfo &BadgesManager::getBadge(int i) {
    return *(badges[i]);
}

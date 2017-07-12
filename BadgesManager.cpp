//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#include <iostream>
#include <typeinfo>
#include <functional>
#include "BadgesManager.h"
#include "BadgeFly.h"
#include "BadgeDeath.h"
#include "BadgeDistance.h"
#include "BadgeObstacle.h"
#include "BadgeScore.h"
#include "BadgeSkull.h"
#include "BadgeSpeed.h"
#include "BadgeStarSkull.h"

BadgesManager *BadgesManager::instance = nullptr;

BadgesManager::BadgesManager() : badgeSize{150}, filename{"../Resources/Saves/badges.dat"}, created{false} {
    badges.emplace_back(new BadgeInfoT<BadgeDeath>("BadgeDeath", "Mr. Death", "5 lost lives", 5));
    badges.emplace_back(new BadgeInfoT<BadgeDistance>("BadgeDistance", "Marathoner", "100 distance points", 100));
    badges.emplace_back(new BadgeInfoT<BadgeFly>("BadgeFly", "Flyer", "Fly on the top of the screen for 100m", 100));
    badges.emplace_back(
            new BadgeInfoT<BadgeObstacle>("BadgeObstacle", "Collector", "10 positive objects in a row", 10));
    badges.emplace_back(new BadgeInfoT<BadgeScore>("BadgeScore", "Champion", "20 total points", 20));
    badges.emplace_back(new BadgeInfoT<BadgeSkull>("BadgeSkull", "Skull", "5 skulls", 5));
    badges.emplace_back(new BadgeInfoT<BadgeSpeed>("BadgeSpeed", "Sprinter", "700 speed points", 700));
    badges.emplace_back(new BadgeInfoT<BadgeStarSkull>("BadgeStarSkull", "Star", "5 stars and skulls", 5));
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

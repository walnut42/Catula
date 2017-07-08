//
// Created by Lorenzo Nuti and Paolo Valcepina on 08/07/17.
//

#include <iostream>
#include <typeinfo>
#include "BadgesManager.h"
#include "BadgeSkull.h"
#include "BadgeFly.h"
#include "BadgeScore.h"

bool BadgesManager::created = false;
const std::string BadgesManager::filename = "../Resources/Saves/badges.dat";
std::map<std::string, BadgeInfo> BadgesManager::badges{
        {"BadgeFly",   BadgeInfo(&createInstance<BadgeFly>)},
        {"BadgeScore", BadgeInfo(&createInstance<BadgeScore>)},
        {"BadgeSkull", BadgeInfo(&createInstance<BadgeSkull>)}
};


void BadgesManager::loadBadges() {
    std::fstream stream;
    stream.open(filename, std::ios::binary | std::ios::in);
    if (stream.is_open()) {
        //1
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
            try {
                badges.at(name).loadBadge(stream);
            }
            catch (std::out_of_range &e) {
                //If a badge has been removed simply does't load it
            }
        }

        //2
//        for (auto &badge:badges)
//            badge.second.loadBadge(stream);
    }
}


void BadgesManager::saveBadges() {
    std::fstream stream;
    stream.open(filename, std::ios::binary | std::ios::out);
    if (stream.is_open()) {
        //1
        //n: number of badges
        int n = static_cast<int>(badges.size());
        writeBinary(stream, n);

        for (auto &badge:badges) {
            //s: length of name
            int s = static_cast<int>(badge.first.length());
            writeBinary(stream, s);
            std::string name = badge.first;
            for (int i = 0; i != s; i++) {
                writeBinary(stream, name[i]);
            }
            badge.second.saveBadge(stream);
        }
//        2
//        for (auto &badge:badges)
//            badge.second.saveBadge(stream);
    }
}

void BadgesManager::createBadgesObservers(MainCharacter *mC) {
    created = true;
    for (auto &badge:badges) {
        badge.second.createBadge(mC);
    }
}

void BadgesManager::destroyBadgesObservers() {
    if (created) {
        for (auto &badge:badges) {
            badge.second.destroyBadge();
        }
        created = false;
    }
}


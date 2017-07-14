//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#ifndef CATULA_SOUNDS_H
#define CATULA_SOUNDS_H

#include <SFML/Audio.hpp>
#include <map>

#include "load_file_error.h"


enum class Sound {
    Menu, Bonus, Zombie, Explosion, Laser, Fail, Life, BadgeUnlocked
};

enum class Music {
    Menu, BadgeMusic, Game
};

class Audio {
public:
    static void loadSounds() throw(load_file_error);

    static void setSound(sf::Sound &sound, Sound name);

    static void setMusic(sf::Music &music, Music name);

private:
    Audio() {};
    static std::map<Sound, sf::SoundBuffer> soundBuffers;
    static std::map<Music, std::string> musicFiles;
};


#endif //CATULA_SOUNDS_H

//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#ifndef CATULA_SOUNDS_H
#define CATULA_SOUNDS_H

#include <map>
#include <SFML/Audio.hpp>


enum class Sound {
    Menu, Laser, Explosion, Bonus, Fail
};

enum class Music {
    Menu, Game
};

class Audio {
public:
    static void loadSounds();

    static void setSound(sf::Sound &sound, Sound name);

    static void setMusic(sf::Music &music, Music name);

private:
    Audio() {};
    static std::map<Sound, sf::SoundBuffer> soundBuffers;
    static std::map<Music, std::string> musicFiles;
};


#endif //CATULA_SOUNDS_H

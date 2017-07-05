//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#include "Audio.h"

std::map<Sound, sf::SoundBuffer> Audio::soundBuffers;
std::map<Music, std::string> Audio::musicFiles;

void Audio::loadSounds() throw(LoadFileError) {
    const std::string error = "Error in sound loading";
    //Sounds
    const std::string path = "../Resources/Audio/";
    std::map<Sound, std::string> soundList = {
            {Sound::Menu,      "footstep.ogg"},
            {Sound::Bonus,     "bonus.ogg"},
            {Sound::Zombie,    "zombie.wav"},
            {Sound::Explosion, "explosion.ogg"},
            {Sound::Laser,     "laser.ogg"},
            {Sound::Fail,      "fail.ogg"},
            {Sound::Life,      "life.ogg"}
    };

    for (const auto &sound:soundList)
        if (!soundBuffers[sound.first].loadFromFile(path + sound.second))
            throw LoadFileError(error, path, sound.second);

    //Musics
    musicFiles[Music::Menu] = path + "darkshadow.wav";
    musicFiles[Music::Game] = path + "nightmare.wav";
}

void Audio::setSound(sf::Sound &sound, Sound name) {
    sound.setBuffer(soundBuffers[name]);
}

void Audio::setMusic(sf::Music &music, Music name) {
    music.openFromFile(musicFiles[name]);
}

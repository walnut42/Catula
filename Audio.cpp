//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#include "Audio.h"

std::map<Sound, sf::SoundBuffer> Audio::soundBuffers;
std::map<Music, std::string> Audio::musicFiles;

void Audio::loadSounds() throw(load_file_error) {
    const std::string error = "Error in sound loading";

    // Sounds.
    const std::string path = "../Resources/Audio/";
    std::map<Sound, std::string> soundList = {
            {Sound::Menu,          "footstep.ogg"},
            {Sound::Bonus,         "bonus.ogg"},
            {Sound::Zombie,        "zombie.wav"},
            {Sound::Explosion,     "explosion.ogg"},
            {Sound::Laser,         "laser.ogg"},
            {Sound::Fail,          "fail.ogg"},
            {Sound::Life,          "life.ogg"},
            {Sound::BadgeUnlocked, "badgeUnlocked.ogg"}
    };

    for (const auto &i:soundList)
        if (!soundBuffers[i.first].loadFromFile(path + i.second))
            throw load_file_error(error, path, i.second);

    // Musics.
    musicFiles[Music::Menu] = path + "darkshadow.wav";
    musicFiles[Music::BadgeMusic] = path + "chineseTorture.wav";
    musicFiles[Music::Game] = path + "nightmare.wav";
}

void Audio::setSound(sf::Sound &sound, Sound name) {
    sound.setBuffer(soundBuffers[name]);
}

void Audio::setMusic(sf::Music &music, Music name) {
    music.openFromFile(musicFiles[name]);
}

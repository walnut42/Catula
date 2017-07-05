//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#include "Audio.h"

std::map<Sound, sf::SoundBuffer> Audio::soundBuffers;
std::map<Music, std::string> Audio::musicFiles;

void Audio::loadSounds() {

    //Sounds
    const std::string path = "../Resources/Audio/";
    soundBuffers[Sound::Menu].loadFromFile(path + "footstep.ogg");
    soundBuffers[Sound::Laser].loadFromFile(path + "laser.ogg");
    soundBuffers[Sound::Explosion].loadFromFile(path + "explosion.ogg");
    soundBuffers[Sound::Bonus].loadFromFile(path + "bonus.ogg");
    soundBuffers[Sound::Fail].loadFromFile(path + "fail.ogg");

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

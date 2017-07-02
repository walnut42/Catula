//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#include "Audio.h"

std::map<Sound, sf::SoundBuffer> Audio::soundBuffers;
std::map<Music, std::string> Audio::musicFiles;


void Audio::loadSounds() {
    //Sounds
    soundBuffers[Sound::Menu].loadFromFile("../Resources/Audio/footstep.ogg");
    soundBuffers[Sound::Laser].loadFromFile("../Resources/Audio/laser.ogg");
    soundBuffers[Sound::Explosion].loadFromFile("../Resources/Audio/explosion.ogg");
    soundBuffers[Sound::Bonus].loadFromFile("../Resources/Audio/bonus.ogg");
    soundBuffers[Sound::Fail].loadFromFile("../Resources/Audio/fail.ogg");

    //Musics
    musicFiles[Music::Menu] = "../Resources/Audio/darkshadow.wav";
    musicFiles[Music::Game] = "../Resources/Audio/nightmare.wav";
}

void Audio::setSound(sf::Sound &sound, Sound name) {
    sound.setBuffer(soundBuffers[name]);
}

void Audio::setMusic(sf::Music &music, Music name) {
    music.openFromFile(musicFiles[name]);
}


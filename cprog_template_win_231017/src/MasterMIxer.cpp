#include "MasterMixer.h"
#include "iostream"
#include "Constants.h"
MasterMixer::MasterMixer(){
    if(Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 4096)<0){
        std::cout << "Could not open the audio device";
    }
}
MasterMixer* MasterMixer::getInstance(){
    static MasterMixer instance;
    return &instance;
}
Mix_Chunk* MasterMixer::loadSound(std::string path){
    Mix_Chunk* sound = Mix_LoadWAV((constants::gResPath + path).c_str());
    if(!sound){
        std::cout <<"Could not load file";
    }
    soundList.push_back(sound);
    return sound;
}
Mix_Music* MasterMixer::loadMusic(std::string path){
    Mix_Music* music = Mix_LoadMUS((constants::gResPath + path).c_str());
    if (!music) {
        std::cout << "Could not load file";
    }
    musicList.push_back(music);
    return music;
}
void MasterMixer::setVolume(int channel, int value){
    Mix_Volume(channel, value);
}
void MasterMixer::playMusic(Mix_Music* music){
    Mix_PlayMusic(music, -1);
}
void MasterMixer::playOneShot(Mix_Chunk* sound){
    Mix_PlayChannel(-1, sound,0);
}
MasterMixer::~MasterMixer(){
    for(Mix_Chunk* sound : soundList){
        Mix_FreeChunk(sound);
    }
    for(Mix_Music* music : musicList){
        Mix_FreeMusic(music);
    }
    Mix_CloseAudio();
}
MasterMixer* mixer = MasterMixer::getInstance();
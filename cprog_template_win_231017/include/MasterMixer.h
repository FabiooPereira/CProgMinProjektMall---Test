#ifndef MASTERMIXER_H
#define MASTERMIXER_H
#include <SDL2/SDL_mixer.h>
#include <string>
#include <vector>
class MasterMixer
{
private:
    /* data */
    std::vector<Mix_Chunk*> soundList; 
    std::vector<Mix_Music*> musicList;
    MasterMixer();
public:
    
    static MasterMixer *getInstance();
    //Ladda upp ljud dvs skapaljud
    Mix_Chunk* loadSound(std::string path);
    Mix_Music* loadMusic(std::string path); 
    //Ändravolym
    void setVolume(int channel, int value);
    //spela Upp ljud 
    void playMusic(Mix_Music* sound);
    void playOneShot(Mix_Chunk* sound);
    //Destructor
    ~MasterMixer();
};
extern MasterMixer* mixer;
#endif
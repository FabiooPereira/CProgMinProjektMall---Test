#ifndef MASTERMIXER_H
#define MASTERMIXER_H
#include <SDL2/SDL_mixer.h>
#include <string>
#include <vector>
class MasterMixer
{
private:
    /* data */
    std::vector<Mix_Chunk*> soundlist; 
    MasterMixer();
public:
    
    static MasterMixer *getInstance();
    //Ladda upp ljud dvs skapaljud
    Mix_Chunk* createSound(std::string name);
    //Ändravolym
    void setVolume(int channel, int value);
    //spela Upp ljud 
    void playMusic(Mix_Chunk* sound);
    void playOneShot(Mix_Chunk* sound);
    ~MasterMixer();
};
#endif
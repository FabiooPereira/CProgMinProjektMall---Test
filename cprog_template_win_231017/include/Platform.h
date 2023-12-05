#ifndef PLATFORM_H
#define PLATFORM_H

#include <Component.h>

class Platform : public Component {
    public:
    static Platform* getInstance(int x, int y, int w, int h);
    virtual void draw() const {};
    void tick(){};

    private:
    Platform(int x, int y, int w, int h); 

    SDL_Texture* texture;

};

#endif
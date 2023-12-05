#ifndef PLATFORM_H
#define PLATFORM_H

#include <Component.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Constants.h"
#include "System.h"
#include <SDL2/SDL_ttf.h>

class Platform : public Component {
    public:
    static Platform* getInstance(int x, int y, int w, int h);
    virtual void draw() const;
    void tick();
    ~Platform();

    protected:
    Platform(int x, int y, int w, int h); 

    private:
    SDL_Texture* texture;

};

#endif
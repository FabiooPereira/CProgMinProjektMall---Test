#ifndef PLATFORM_H
#define PLATFORM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Component.h"
#include "Constants.h"
#include "System.h"

class Platform : public Component
{
public:
    static Platform *getInstance(int x, int y, int w, int h, bool collsion);
    virtual void draw() const;
    void tick(){}
    ~Platform();

protected:
    Platform(int x, int y, int w, int h, bool collision);

private:
    SDL_Texture *texture;
    // const int width = 100;
    // const int height = 20;
};
#endif
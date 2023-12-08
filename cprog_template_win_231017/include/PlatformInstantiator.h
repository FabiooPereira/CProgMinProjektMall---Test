#ifndef PLATFORMINSTANTIATOR_H
#define PLATFORMINSTANTIATOR_H

#include <Component.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Constants.h"
#include "System.h"
#include <SDL2/SDL_ttf.h>
#include<vector>

class PlatformInstantiator : public Component
{
private:
    float recentDistance;
    const int distanceInterval = 50;
    int platforms;
    int maxPlatforms = 16;
    std::vector<Component *> objects;
    std::vector<Component *> toRemove;
    void createPlatform();
    void checkOutOfScope();
    void removeOutOfScope();
    //int distanceMoved;

public:
    PlatformInstantiator();
    static PlatformInstantiator *getInstance();
    void draw() const;
    void tick();
    ~PlatformInstantiator(){}

protected:
};

#endif
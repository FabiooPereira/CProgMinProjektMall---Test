#ifndef PLATFORMINSTANTIATOR_H
#define PLATFORMINSTANTIATOR_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Component.h"
#include "Constants.h"
#include "System.h"
#include "Platform.h"

class PlatformInstantiator : public Component
{
private:
    float recentDistance;
    const int distanceInterval = 50;
    int platforms;
    int maxPlatforms = 16;

    void createPlatform();
    void checkOutOfScope();

public:
    PlatformInstantiator();
    static std::shared_ptr<PlatformInstantiator> getInstance();
    void draw() const override {}
    void tick() override;
    ~PlatformInstantiator() override {}

protected:
};

#endif
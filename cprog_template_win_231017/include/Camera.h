#ifndef CAMERA_H
#define CAMERA_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Component.h"

class Camera : public Component
{
public:
    static double distanceMoved;
    static Camera *getInstance(Component *playerComponent);

    void draw() const {}

    void tick();
    ~Camera();

protected:
    Camera(Component *component);

private:
    Component *componentToFollow;
    float toMove;
};

#endif
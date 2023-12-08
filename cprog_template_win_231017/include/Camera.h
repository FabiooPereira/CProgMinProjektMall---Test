#ifndef CAMERA_H
#define CAMERA_H

#include "Component.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Constants.h"
#include "System.h"
#include <SDL2/SDL_ttf.h>

class Camera : public Component
{
public:
    // static int d;
    // static int getd() { return d; }
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
   //double distanceMoved;
};

#endif
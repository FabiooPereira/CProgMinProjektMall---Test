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
    static std::shared_ptr<Camera> getInstance(std::shared_ptr<Component> target);

    void draw() const override {}

    void tick() override;
    ~Camera() override;

protected:
    Camera(std::shared_ptr<Component> target);

private:
    std::shared_ptr<Component> componentToFollow;
    float toMove;
};

#endif
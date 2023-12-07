#include "Component.h"
#include <iostream>

Component::Component(int x, int y, int w, int h) : rect{x, y, w, h}, collider(false),
                                                   frect{(float)x, (float)y, (float)w, (float)h}
{
}
Component::Component(int x, int y, int w, int h, bool colliderOn) : rect{x, y, w, h}, collider(colliderOn),
                                                                    frect{(float)x, (float)y, (float)w, (float)h}
{
}
// void Component::setRect(const SDL_Rect &newRect)
// {
//     rect = newRect;
// }
void Component::setFRect(const SDL_FRect &newRect)
{
    frect = newRect;
}
void Component::onCollision(Component *c)
{
    // std::cout << "collision! F" << std::endl;
}

void Component::move(const float x, const float y)
{
    frect.x += x;
    frect.y += y;
    setFRect(frect);
}
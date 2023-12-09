#include <iostream>
#include "Component.h"

Component::Component(int x, int y, int w, int h) : rect{x, y, w, h}, collider(false)
{
}
Component::Component(int x, int y, int w, int h, bool colliderOn) : rect{x, y, w, h}, collider(colliderOn)
{
}
void Component::setRect(const SDL_Rect &newRect)
{
    rect = newRect;
}
void Component::onCollision(Component *c)
{
    // std::cout << "collision! F" << std::endl;
}

void Component::move(const int x, const int y)
{
    rect.x += x;
    rect.y += y;
    setRect(rect);
}
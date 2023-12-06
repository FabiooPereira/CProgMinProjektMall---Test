#include "Component.h"
#include <iostream>

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
    std::cout << "collision! F";
}



void * Component::operator new(size_t size)
{
    std::cout << "memory allocated: " << size << std::endl;

    return malloc(size);
}
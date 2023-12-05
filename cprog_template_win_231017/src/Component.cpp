#include "Component.h"
#include <iostream>


Component::Component(int x, int y, int w, int h) : rect{x, y, w, h}, collision(false)
{
}
Component::Component(int x, int y, int w, int h, bool colliderOn) : rect{x, y, w, h}, collision(colliderOn)
{
}
void Component::setRect(const SDL_Rect &newRect){
    rect = newRect;
}
void onCollision(Component *c)
{
    std::cout << "collision! F";
}
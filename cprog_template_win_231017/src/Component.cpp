#include "Component.h"
#include <iostream>

//HEJ Test

Component::Component(int x, int y, int w, int h) : rect{x, y, w, h}
{
}
void Component::setRect(const SDL_Rect &newRect){
    rect = newRect;
}
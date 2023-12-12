#include <iostream>
#include "Component.h"

int Component::createCount = 0;
int Component::deleteCount = 0;
int Component::leftOverCount = 0;

Component::Component(int x, int y, int w, int h) : rect{x, y, w, h}, collider(false)
{
    createCount++;
}
Component::Component(int x, int y, int w, int h, bool colliderOn) : rect{x, y, w, h}, collider(colliderOn)
{
    createCount++;
}
void Component::setRect(const SDL_Rect &newRect)
{
    rect = newRect;
}
void Component::onCollision(std::shared_ptr<Component> c)
{
    // std::cout << "collision! F" << std::endl;
}

void Component::move(const int x, const int y)
{
    rect.x += x;
    rect.y += y;
    setRect(rect);
}

Component::~Component()
{
    deleteCount++;
    leftOverCount = createCount - deleteCount;
    Component::printCounts();
}

void Component::printCounts()
{
    std::cout << "components created: " << createCount << std::endl;
    std::cout << "components deleted: " << deleteCount << std::endl;
    std::cout << "components leftover: " << leftOverCount << std::endl;
}
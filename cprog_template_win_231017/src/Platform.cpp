#include "Platform.h"

Platform *Platform::getInstance(int x, int y, int w, int h, bool collision)
{
    return new Platform(x, y, w, h, collision);
}
std::shared_ptr<Platform> Platform::getInstance(int x, int y)
{
    return std::shared_ptr<Platform>(new Platform(x, y, 120, 20, true));
}

void Platform::draw() const
{
    SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());
}

Platform::Platform(int x, int y, int w, int h, bool collision) : Component(x, y, w, h, collision)
{
    std::cout << "platform  created: " << this << std::endl;
    texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/Platform.png").c_str());
}
Platform::~Platform()
{
    SDL_DestroyTexture(texture);
    std::cout << "platform  destructed: " << this << std::endl;
}

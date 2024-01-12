#include "Platform.h"
#include "System.h"
#include "Constants.h"

namespace scribbleHop
{
    std::shared_ptr<Platform> Platform::getInstance(int x, int y, int w, int h, bool collision)
    {
        return std::shared_ptr<Platform>(new Platform(x, y, 120, 20, true));
    }

    void Platform::draw() const
    {
        SDL_RenderCopy(engine::sys.get_ren(), texture, NULL, &getRect());
    }

    Platform::Platform(int x, int y, int w, int h, bool collision) : Component(x, y, w, h, collision)
    {
        // std::cout << "platform  created: " << this << std::endl;
        texture = IMG_LoadTexture(engine::sys.get_ren(), (constants::gResPath + "images/Platform.png").c_str());
    }
    Platform::~Platform()
    {
        SDL_DestroyTexture(texture);
        // std::cout << "platform  destructed: " << this << std::endl;
    }
}
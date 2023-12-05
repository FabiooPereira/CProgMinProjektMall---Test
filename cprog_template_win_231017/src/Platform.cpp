#include "Platform.h"

using namespace std;

namespace engine
{
    Platform *Platform::getInstance(int x, int y, int w, int h, bool collision)
    {
        return new Platform(x, y, w, h, collision);
    };

    void Platform::draw() const
    {
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());
    };

    void Platform::tick(){
        // SDL_Rect platformRect = getRect();
        // platformRect.y += 5;
        // setRect(platformRect);
    };

    Platform::~Platform(){};

    Platform::Platform(int x, int y, int w, int h, bool collision) : Component(x, y, w, h, collision)
    {
        texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/Platform.png").c_str());
    };
}
#ifndef PLATFORM_H
#define PLATFORM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Component.h"
#include "Constants.h"
#include "System.h"

namespace scribbleHop
{
    class Platform : public engine::Component
    {
    public:
        static std::shared_ptr<Platform> getInstance(int x, int y, int w, int h, bool collision);
        void draw() const override;
        void tick() override {}
        ~Platform() override;

    protected:
        Platform(int x, int y, int w, int h, bool collision);

    private:
        SDL_Texture *texture;
    };
}
#endif
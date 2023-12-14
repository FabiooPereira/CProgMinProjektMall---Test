#include "Button.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "Constants.h"
#include "System.h"
#include <iostream>
using namespace std;

Button::Button(int x, int y, int w, int h, std::string t) : Component(x, y, w, h), text(t)
{
    SDL_Surface *surf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), {255, 255, 255, 255});
    texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
    SDL_FreeSurface(surf);
    upImage = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/bg.jpg").c_str());
    downImage = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/bg.jpg").c_str());
}

std::shared_ptr<Button> Button::getInstance(int x, int y, int w, int h, std::string t)
{
    return std::shared_ptr<Button>(new Button(x, y, w, h, t));
}

Button::~Button()
{
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(upImage);
    SDL_DestroyTexture(downImage);
}

void Button::draw() const
{
    if (isDown)
    {
        SDL_RenderCopy(sys.get_ren(), downImage, NULL, &getRect());
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());
    }

    else
    {
        SDL_RenderCopy(sys.get_ren(), upImage, NULL, &getRect());
    }
}

void Button::mouseUp(const SDL_Event &eve)
{
    SDL_Point p = {eve.button.x, eve.button.y};
    if (SDL_PointInRect(&p, &getRect()))
        perform(shared_from_this());
    isDown = false;
}
void Button::mouseDown(const SDL_Event &eve)
{
    SDL_Point p = {eve.button.x, eve.button.y};
    if (SDL_PointInRect(&p, &getRect()))
        isDown = true;
}
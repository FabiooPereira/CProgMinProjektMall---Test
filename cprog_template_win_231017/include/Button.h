#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>
#include "Component.h"
#include <string>

class Button : public Component
{
public:
    static Button *getInstance(int x, int y, int w, int h, std::string t);
    ~Button();
    void draw() const;
    void mouseUp(const SDL_Event &eve);
    void mouseDown(const SDL_Event &eve);
    virtual void perform(Button *source) {}
    void tick() {}

protected:
    Button(int x, int y, int w, int h, std::string txt);

private:
    std::string text;
    SDL_Rect rect;
    SDL_Texture *texture;
    SDL_Texture *upImage, *downImage;
    bool isDown = false;
};

#endif
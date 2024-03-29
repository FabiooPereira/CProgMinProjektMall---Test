#ifndef BUTTON_H
#define BUTTON_H

#include "Component.h"
#include <string>
namespace engine
{
    class Button : public Component, public std::enable_shared_from_this<Button>
    {
    public:
        static std::shared_ptr<Button> getInstance(int x, int y, int w, int h, std::string t);

        void mouseUp(const SDL_Event &eve) override;
        void mouseDown(const SDL_Event &eve) override;
        virtual void perform(std::shared_ptr<Button> source) {}
        void tick() override {}
        void draw() const override;
        ~Button() override;

    protected:
        Button(int x, int y, int w, int h, std::string txt);

    private:
        std::string text;
        SDL_Texture *texture;
        SDL_Texture *upImage, *downImage;
        bool isDown = false;
    };
}
#endif
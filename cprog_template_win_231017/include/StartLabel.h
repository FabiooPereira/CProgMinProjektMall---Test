#ifndef STARTLABEL_H
#define STARTLABEL_H
#include "Label.h"

namespace scribbleHop
{
    class StartLabel : public engine::Label
    {
    public:
        static std::shared_ptr<StartLabel> getInstance(int x, int y, int w, int h, std::string t);
        void keyDown(const SDL_Event &eve) override;
    private:
        StartLabel(int x, int y, int w, int h, std::string t);
    };
}

#endif
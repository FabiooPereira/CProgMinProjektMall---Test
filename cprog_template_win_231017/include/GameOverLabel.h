#ifndef GAMEOVERLABEL_H
#define GAMEOVERLABEL_H
#include "Label.h"
namespace scribbleHop
{
    class GameOverLabel : public engine::Label
    {
    public:
        static std::shared_ptr<GameOverLabel> getInstance(int x, int y, int w, int h, std::string t);
        void keyDown(const SDL_Event &eve) final;
        void tick() override {}
        ~GameOverLabel() {}

    private:
        GameOverLabel(int x, int y, int w, int h, std::string t);
    };

}
#endif
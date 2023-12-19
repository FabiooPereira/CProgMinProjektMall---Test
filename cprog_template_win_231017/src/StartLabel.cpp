#include "StartLabel.h"
#include "SceneManager.h"

namespace scribbleHop
{
    std::shared_ptr<StartLabel> StartLabel::getInstance(int x, int y, int w, int h, std::string t)
    {
        return std::shared_ptr<StartLabel>(new StartLabel(x, y, w, h, t));
    }
    void StartLabel::keyDown(const SDL_Event &eve)
    {
        engine::manager->loadScene("Game");
    }

    StartLabel::StartLabel(int x, int y, int w, int h, std::string t) : Label(x, y, w, h, t) {}
}
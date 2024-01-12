#include "GameOverLabel.h"
#include "SceneManager.h"
#include <string>

namespace scribbleHop
{
    std::shared_ptr<GameOverLabel> GameOverLabel::getInstance(int x, int y, int w, int h, std::string t)
    {
        return std::shared_ptr<GameOverLabel>(new GameOverLabel(x, y, w, h, t));
    }
    void GameOverLabel::keyDown(const SDL_Event &eve)
    {
        switch (eve.key.keysym.sym)
        {
        case SDLK_SPACE:
            engine::manager->loadScene("Game");
            break;
        case SDLK_q:
            engine::manager->getScene(engine::manager->getCurrentScene())->exit();
            break;
        default:
            //std::cout << "wrong input pressed" << std::endl;
            break;
        }
    }

    GameOverLabel::GameOverLabel(int x, int y, int w, int h, std::string t) : Label(x, y, w, h, t) {}
}
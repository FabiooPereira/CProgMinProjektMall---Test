#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <memory>
#include "Session.h"
#include "Label.h"
#include "Button.h"
#include "Player.h"
#include "Platform.h"
#include "Camera.h"
#include "PlatformInstantiator.h"
#include "MasterMixer.h"

#define FPS 60
using namespace std;

bool play;
void createStartScreen();
void createDoodleJump();
void createGameOverScreen();

class StartLabel : public Label
{
public:
    static std::shared_ptr<StartLabel> getInstance()
    {
        return std::shared_ptr<StartLabel>(new StartLabel());
    }
    void keyDown(const SDL_Event &eve) override
    {
        startScreen.exit();
    }
    void tick() override {}
    ~StartLabel() {}

protected:
    StartLabel() : Label(50, 500, 400, 50, "Press any key to start") {}
};

class GameOverLabel : public Label
{
public:
    static std::shared_ptr<GameOverLabel> getInstance()
    {
        return std::shared_ptr<GameOverLabel>(new GameOverLabel());
    }
    void keyDown(const SDL_Event &eve) override
    {
        switch (eve.key.keysym.sym)
        {
        case SDLK_SPACE:
            std::cout << "space pressed" << std::endl;
            play = true;
            break;
        case SDLK_q:
            std::cout << "q pressed" << std::endl;
            play = false;
            break;
        default:
            play = false;
            break;
        }
        gameoverScreen.exit();
    }
    void tick() override {}
    ~GameOverLabel() {}

protected:
    GameOverLabel() : Label(50, 700, 400, 50, "Press 'space' to play again") {}
};

int main(int argv, char **args)
{
    play = true;
    createStartScreen();
    startScreen.run();
    while (play)
    {
        createDoodleJump();
        ses.run();
        createGameOverScreen();
        gameoverScreen.run();
    }
    std::cout << "after run()" << std::endl;

    return 0;
}

void createStartScreen()
{
    startScreen.add(Label::getInstance(25, 200, 450, 50, "ScribbleHop"));
    startScreen.add(StartLabel::getInstance());
}

void createDoodleJump()
{
    // Mix_Music *bgMusic = mixer->loadMusic("BacgroundMusic_489035__michael-db__game-music-01.wav");
    // mixer->playMusic(bgMusic);

    ses.add(PlatformInstantiator::getInstance());

    ses.add(Platform::getInstance(200, 880, 120, 20, true));

    ses.add(Platform::getInstance(150, 600, 120, 20, true));

    ses.add(Platform::getInstance(100, 300, 120, 20, true));

    ses.add(Platform::getInstance(200, 200, 120, 20, true));

    ses.add(Platform::getInstance(150, 100, 120, 20, true));

    ses.add(Platform::getInstance(100, 50, 120, 20, true));

    shared_ptr<Player> player = Player::getInstance(250, 850, 100, 100, true);
    player->setSprite("Player_Idle.png");
    player->setAnimation(6);
    ses.add(player);
    ses.add(Camera::getInstance(player));
}

void createGameOverScreen()
{
    gameoverScreen.add(Label::getInstance(50, 100, 400, 100, "Game Over"));
    gameoverScreen.add(Label::getInstance(50, 200, 400, 100, "Distance traveled:"));
    gameoverScreen.add(Label::getInstance(50, 300, 400, 150, std::to_string((int)Camera::distanceMoved)));
    gameoverScreen.add(Label::getInstance(50, 750, 400, 50, "Press 'Q' to quit"));
    gameoverScreen.add(GameOverLabel::getInstance());
}
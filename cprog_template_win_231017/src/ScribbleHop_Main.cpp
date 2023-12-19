#include <iostream>
#include "Session.h"
#include "Label.h"
#include "Button.h"
#include "Player.h"
#include "Platform.h"
#include "Camera.h"
#include "PlatformInstantiator.h"
#include "MasterMixer.h"
#include "SceneManager.h"
#include "DoodlePlayer.h"
#include "StartLabel.h"
#include "GameOverLabel.h"

using namespace scribbleHop;
using namespace engine;

void createStartScreen()
{
    manager->getScene("Start")->add(Label::getInstance(25, 200, 450, 50, "ScribbleHop"));
    manager->getScene("Start")->add(StartLabel::getInstance(50, 500, 400, 50, "Start"));
}

void createDoodleJump()
{
    manager->getScene("Game")->add(PlatformInstantiator::getInstance());
    manager->getScene("Game")->add(Platform::getInstance(200, 880, 120, 20, true));
    manager->getScene("Game")->add(Platform::getInstance(150, 600, 120, 20, true));
    manager->getScene("Game")->add(Platform::getInstance(100, 300, 120, 20, true));
    manager->getScene("Game")->add(Platform::getInstance(200, 200, 120, 20, true));
    manager->getScene("Game")->add(Platform::getInstance(150, 100, 120, 20, true));
    manager->getScene("Game")->add(Platform::getInstance(100, 50, 120, 20, true));

    std::shared_ptr<DoodlePlayer> player = DoodlePlayer::getInstance();
    manager->getScene("Game")->add(player);
    manager->getScene("Game")->add(Camera::getInstance(player));
}

void createGameOverScreen()
{
    manager->getScene("GameOver")->add(Label::getInstance(50, 100, 400, 100, "Game Over"));
    manager->getScene("GameOver")->add(Label::getInstance(75, 200, 350, 50, "Distance traveled:"));
    manager->getScene("GameOver")->add(Label::getInstance(50, 300, 400, 150, std::to_string((int)Camera::getDistanceMoved())));
    manager->getScene("GameOver")->add(Label::getInstance(50, 750, 400, 50, "Press 'Q' to quit"));
    manager->getScene("GameOver")->add(GameOverLabel::getInstance(50, 700, 400, 50, "Press 'space' to play again"));
}

int main(int argv, char **args)
{
    Mix_Music *bgMusic = mixer->loadMusic("BacgroundMusic_489035__michael-db__game-music-01.wav");
    mixer->playMusic(bgMusic);
    manager->createScene("Start", *createStartScreen);
    manager->createScene("Game", *createDoodleJump);
    manager->createScene("GameOver", *createGameOverScreen);

    manager->loadScene("Start");
    while (!manager->isQueueEmpty())
    {
        manager->runNext();
    }
    std::cout << "returning 0" << std::endl;
    return 0;
}
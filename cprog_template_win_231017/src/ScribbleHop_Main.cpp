#include <iostream>
#include <string>
#include <memory>
#include "Session.h"
#include "Label.h"
#include "Button.h"
#include "Player.h"
#include "Platform.h"
#include "Camera.h"
#include "PlatformInstantiator.h"
#include "MasterMixer.h"
#include "SceneManager.h"

using namespace std;

class StartButton : public Button
{
public:
    static std::shared_ptr<StartButton> getInstance(int x, int y, int w, int h)
    {
        return std::shared_ptr<StartButton>(new StartButton(x, y, w, h));
    }
    void perform(std::shared_ptr<Button> source) final
    {
        manager->loadScene("Game");
    }

private:
    StartButton(int x, int y, int w, int h) : Button(x, y, w, h, "Start") {}
};

class DoodlePlayer : public Player
{
public:
    static std::shared_ptr<DoodlePlayer> getInstance()
    {
        return std::shared_ptr<DoodlePlayer>(new DoodlePlayer());
    }

    void tick() override
    {
        Player::tick(); // kör "bas-Player::tick()" som just nu bara uppdaterar animationen
        applyVelocity();
        if (getRect().y > sys.get_height()) // kollar om den är utanför skärmen
        {
            manager->loadScene("GameOver"); // byter till gameover-scenen
        }
    }

    void onCollision(std::shared_ptr<Component> c) final
    {
        if (!jumping && (c->getRect().y - getRect().y) > getRect().h - 10)
        {
            jumping = true; // Reset jumping when colliding with something
            velocity = 1;
            mixer->playOneShot(mixer->loadSound("Jump.wav"));
        }
    }

    void applyVelocity()
    {
        if (jumping)
        {
            jump();
        }
        if (velocity < 10)
            velocity *= gravity; // Applying gravity
        move(0, velocity);
    }

    void jump()
    {
        move(0, -jumpForce);
        jumpForce--; // Reducing jump force to simulate decreasing force over time
        if (jumpForce <= 0)
        {
            jumping = false; // Stop jumping when jump force is exhausted
            jumpForce = 30;
        }
    }

protected:
    DoodlePlayer() : Player(250, 750, 100, 100, true)
    {
        velocity = 1;
        jumping = false;
        jumpForce = 30; // Adjust the jump force as needed
        gravity = 1.05; // Adjust the gravity as needed
        setSprite("Player_Idle.png");
        setAnimation(6);
    }
};

class StartLabel : public Label
{
public:
    static std::shared_ptr<StartLabel> getInstance()
    {
        return std::shared_ptr<StartLabel>(new StartLabel());
    }
    void keyDown(const SDL_Event &eve) override
    {
        manager->loadScene("Game");
    }
    void tick() override {}
    ~StartLabel() override {}

protected:
    StartLabel() : Label(50, 500, 400, 50, "Start") {}
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
            manager->loadScene("Game");
            break;
        case SDLK_q:
            manager->getScene(SceneManager::currentScene)->exit();
            break;
        default:
            std::cout << "wrong input pressed" << std::endl;
            break;
        }
    }
    void tick() override {}
    ~GameOverLabel() {}

protected:
    GameOverLabel() : Label(50, 700, 400, 50, "Press 'space' to play again") {}
};

void createStartScreen()
{
    manager->getScene("Start")->add(Label::getInstance(25, 200, 450, 50, "ScribbleHop"));
    manager->getScene("Start")->add(StartButton::getInstance(50, 500, 400, 50));
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

    shared_ptr<DoodlePlayer> player = DoodlePlayer::getInstance();
    manager->getScene("Game")->add(player);
    manager->getScene("Game")->add(Camera::getInstance(player));
}

void createGameOverScreen()
{
    manager->getScene("GameOver")->add(Label::getInstance(50, 100, 400, 100, "Game Over"));
    manager->getScene("GameOver")->add(Label::getInstance(75, 200, 350, 50, "Distance traveled:"));
    manager->getScene("GameOver")->add(Label::getInstance(50, 300, 400, 150, std::to_string((int)Camera::distanceMoved)));
    manager->getScene("GameOver")->add(Label::getInstance(50, 750, 400, 50, "Press 'Q' to quit"));
    manager->getScene("GameOver")->add(GameOverLabel::getInstance());
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
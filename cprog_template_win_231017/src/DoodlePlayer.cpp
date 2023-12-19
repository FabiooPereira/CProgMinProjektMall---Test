#include "DoodlePlayer.h"
#include "MasterMixer.h"
#include "SceneManager.h"

namespace scribbleHop
{
    std::shared_ptr<DoodlePlayer> DoodlePlayer::getInstance()
    {
        return std::shared_ptr<DoodlePlayer>(new DoodlePlayer());
    }

    void DoodlePlayer::keyDown(const SDL_Event &eve)
    {
        switch (eve.key.keysym.sym)
        {
        case SDLK_LEFT:
            move(-20, 0);
            break;
        case SDLK_RIGHT:
            move(20, 0);
            break;
        default:
            break;
        }
    }

    void DoodlePlayer::tick()
    {
        Player::tick(); // kör "bas-Player::tick()" som just nu bara uppdaterar animationen
        applyVelocity();
        if (getRect().y > engine::sys.get_height()) // kollar om den är utanför skärmen
        {
            engine::manager->loadScene("GameOver"); // byter till gameover-scenen
        }
    }

    void DoodlePlayer::onCollision(std::shared_ptr<Component> c)
    {
        if (!jumping && (c->getRect().y - getRect().y) > getRect().h - 15)
        {
            jumping = true; // Reset jumping when colliding with something
            velocity = 1;
            engine::mixer->playOneShot(engine::mixer->loadSound("Jump.wav"));
        }
    }

    void DoodlePlayer::applyVelocity()
    {
        if (jumping)
        {
            jump();
        }
        if (velocity < 10)
            velocity *= gravity; // Applying gravity
        move(0, velocity);
    }

    void DoodlePlayer::jump()
    {
        move(0, -jumpForce);
        jumpForce--; // Reducing jump force to simulate decreasing force over time
        if (jumpForce <= 0)
        {
            jumping = false; // Stop jumping when jump force is exhausted
            jumpForce = 30;
        }
    }

    DoodlePlayer::DoodlePlayer() : Player(250, 750, 100, 100, true)
    {
        velocity = 1;
        jumping = false;
        jumpForce = 30; // Adjust the jump force as needed
        gravity = 1.05; // Adjust the gravity as needed
        setSprite("Player_Idle.png");
        setAnimation(6);
    }
}
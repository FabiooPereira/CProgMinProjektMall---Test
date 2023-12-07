#include "Player.h"
#include <iostream>

Player::Player(int xPos, int yPos, int w, int h, bool collision) : Component(xPos, yPos, w, h, collision)
{
    idleSpriteSheet = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/PlayerIdle.png").c_str());

    currentFrame = 0;
    frameCounter = 0;
    animationSpeed = 10;
    velocity = 1;
    jumping = false;
    jumpForce = 30; // Adjust the jump force as needed
    gravity = 1.05; // Adjust the gravity as needed
}

Player *Player::getInstance(int x, int y, int w, int h, bool collision)
{
    return new Player(x, y, w, h, collision);
}

void Player::draw() const
{
    SDL_Rect srcRect = {currentFrame * 48, 0, 48, 48};
    SDL_RenderCopy(sys.get_ren(), activeSpriteSheet(), &srcRect, &getRect());
}

void Player::keyDown(const SDL_Event &eve)
{
    // SDL_Rect playerRect = getRect();
    switch (eve.key.keysym.sym)
    {
    case SDLK_LEFT:
        // playerRect.x -= 20;
        move(-20, 0);
        break;
    case SDLK_RIGHT:
        // playerRect.x += 20;
        move(20, 0);
        break;
    case SDLK_UP:
        if (!jumping) // Allowing jumping only when not already jumping
        {
            jumping = true;
            jumpForce = 30; // Resetting jump force for each jump
        }
        break;
    case SDLK_DOWN:
        // playerRect.y += 10;
        move(0, 10);
        break;
    default:
        break;
    }
    // setRect(playerRect);
}

void Player::keyUp(const SDL_Event &even)
{
}

void Player::tick()
{
    // SDL_Rect playerRect = getRect();
    // applyVelocity(&playerRect);
    // setRect(playerRect);
    // std::cout << "Velocity: " << velocity << std::endl;

    applyVelocity();
    frameCounter++;
    if (frameCounter >= animationSpeed)
    {
        currentFrame = (currentFrame + 1) % 6;
        frameCounter = 0;
    }
}

void Player::applyVelocity()
{
    if (jumping)
    {
        jump();
    }
    if (velocity < 10)
        velocity *= gravity; // Applying gravity
    move(0, velocity);
}

// void Player::applyVelocity(SDL_Rect *rect)
// {
//     if (jumping)
//     {
//         jump(jumpForce, rect);
//     }
//     if (velocity < 10)
//         velocity *= gravity; // Applying gravity
//     rect->y += velocity;
// }

void Player::jump()
{
    move(0, -jumpForce);
    jumpForce--; // Reducing jump force to simulate decreasing force over time
    if (jumpForce <= 0)
    {
        jumping = false; // Stop jumping when jump force is exhausted
        jumpForce = 30;
    }
}

// void Player::jump(int force, SDL_Rect *rect)
// {
//     rect->y -= force;
//     jumpForce--; // Reducing jump force to simulate decreasing force over time
//     if (jumpForce <= 0)
//     {
//         jumping = false; // Stop jumping when jump force is exhausted
//         jumpForce = 30;
//     }
// }

void Player::onCollision(Component *c)
{
    jumping = true; // Reset jumping when colliding with something
    velocity = 1;
}

SDL_Texture *Player::activeSpriteSheet() const
{
    return idleSpriteSheet;
}

Player::~Player()
{
    std::cout << "player destruct" << std::endl;
    SDL_DestroyTexture(idleSpriteSheet);
    SDL_DestroyTexture(RunSpriteSheet);
}

#include <iostream>
#include "Player.h"
#include "MasterMixer.h"

Player::Player(int xPos, int yPos, int w, int h, bool collision) : Component(xPos, yPos, w, h, collision)
{
    std::cout << "player created: " << this << std::endl;
    idleSpriteSheet = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/Player_Idle.png").c_str());

    currentFrame = 0;
    frameCounter = 0;
    animationSpeed = 10;
    velocity = 1;
    jumping = false;
    jumpForce = 30; // Adjust the jump force as needed
    gravity = 1.05; // Adjust the gravity as needed
}

Player::~Player()
{
    std::cout << "player destructed: " << this << std::endl;
    SDL_DestroyTexture(idleSpriteSheet);
    SDL_DestroyTexture(RunSpriteSheet);
}

std::shared_ptr<Player> Player::getInstance(int x, int y, int w, int h, bool collision)
{
    return std::shared_ptr<Player>(new Player(x, y, w, h, collision));
}
void Player::draw() const
{
    SDL_Rect srcRect = {(currentFrame * 48) + 17, 0, 20, 20}; // Hårdkodat PLS FIX
    SDL_RenderCopy(sys.get_ren(), activeSpriteSheet(), &srcRect, &getRect());
}

void Player::keyDown(const SDL_Event &eve)
{
    switch (eve.key.keysym.sym)
    {
    case SDLK_LEFT:
        move(-20, 0);
        break;
    case SDLK_RIGHT:
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
        move(0, 10);
        break;
    default:
        break;
    }
}

void Player::keyUp(const SDL_Event &even)
{
}

void Player::tick()
{
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

void Player::onCollision(std::shared_ptr<Component> c)
{
    if (!jumping)
    {
        jumping = true; // Reset jumping when colliding with something
        velocity = 1;
        Mix_Chunk *jumpFX = mixer->loadSound("Jump.wav");
        mixer->playOneShot(jumpFX);
    }
}

SDL_Texture *Player::activeSpriteSheet() const
{
    return idleSpriteSheet;
}
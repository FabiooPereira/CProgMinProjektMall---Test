#include <iostream>
#include "Player.h"
#include "MasterMixer.h"

Player::Player(int xPos, int yPos, int w, int h, bool collision) : Component(xPos, yPos, w, h, collision)
{
    std::cout << "player created: " << this << std::endl;
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
}

std::shared_ptr<Player> Player::getInstance(int x, int y, int w, int h, bool collision)

{
    return std::shared_ptr<Player>(new Player(x, y, w, h, collision));
}

void Player::draw() const
{
    SDL_Rect srcRect;
    srcRect.x = currentFrame * frameWidth; 
    srcRect.y = 0; 
    srcRect.w = frameWidth; 
    srcRect.h = frameHeight; 

    SDL_RenderCopy(sys.get_ren(), idleSpriteSheet, &srcRect, &getRect());
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
        currentFrame = (currentFrame + 1) % frameCount;
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

void Player::setSprite(const std::string& imageFile) {
    imageFileURL = imageFile;
    SDL_DestroyTexture(idleSpriteSheet);
    idleSpriteSheet = IMG_LoadTexture(sys.get_ren(), (constants::gResImagePath + imageFileURL).c_str());
}

void Player::setAnimation(int frames) {

    SDL_QueryTexture(idleSpriteSheet, NULL, NULL, &spriteSheetWidth, &spriteSheetHeight);

    frameCount = frames;
    frameWidth = spriteSheetWidth / frameCount;
    frameHeight = spriteSheetHeight;

}
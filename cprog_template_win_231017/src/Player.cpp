#include <iostream>
#include "Player.h"
#include "MasterMixer.h"

Player::Player(int xPos, int yPos, int w, int h, bool collision) : Component(xPos, yPos, w, h, collision)
{
    std::cout << "player created: " << this << std::endl;
    currentFrame = 0;
    frameCounter = 0;
    animationSpeed = 10;
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
        // leftfunction
        move(-20, 0);
        break;
    case SDLK_RIGHT:
        // rightfunction
        move(20, 0);
        break;
    case SDLK_UP:
        // upfunction
        if (!jumping) // Allowing jumping only when not already jumping
        {
            jumping = true;
            jumpForce = 30; // Resetting jump force for each jump
        }
        break;
    case SDLK_DOWN:
        // downfunction
        move(0, 10);
        break;
    default:
        break;
    }
}

void Player::tick()
{
    updateFrame();
}

void Player::updateFrame()
{

    frameCounter++;
    if (frameCounter >= animationSpeed)
    {
        currentFrame = (currentFrame + 1) % frameCount;
        frameCounter = 0;
    }
}

void Player::onCollision(std::shared_ptr<Component> c)
{
}

void Player::setSprite(const std::string &imageFile)
{
    imageFileURL = imageFile;
    SDL_DestroyTexture(idleSpriteSheet);
    idleSpriteSheet = IMG_LoadTexture(sys.get_ren(), (constants::gResImagePath + imageFileURL).c_str());
}

void Player::setAnimation(int frames)
{
    SDL_QueryTexture(idleSpriteSheet, NULL, NULL, &spriteSheetWidth, &spriteSheetHeight);

    frameCount = frames;
    frameWidth = spriteSheetWidth / frameCount;
    frameHeight = spriteSheetHeight;
}
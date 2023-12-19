#include <iostream>
#include "Player.h"
#include "MasterMixer.h"

namespace engine
{
    Player::Player(int xPos, int yPos, int w, int h, bool collision) : Component(xPos, yPos, w, h, collision)
    {
        currentFrame = 0;
        frameCounter = 0;
        animationSpeed = 10;
    }

    Player::~Player()
    {
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

    void Player::tick() // kan overridas men och köras genom Player::tick()
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
}
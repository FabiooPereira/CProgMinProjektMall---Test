#include "Player.h"

Player::Player(int xPos, int yPos, int w, int h) : Component(xPos, yPos, w, h)
{
    idleSpriteSheet = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/PlayerIdle.png").c_str());

    currentFrame = 0;
    frameCountter = 0;
    animationSpeed = 10;
}
Player *Player::getInstance(int x, int y, int w, int h)
{
    return new Player(x, y, w, h);
}
void Player::draw() const
{
    SDL_Rect srcRect = {currentFrame * 48, 0, 48, 48};
    SDL_RenderCopy(sys.get_ren(), activeSpriteSheet(), &srcRect, &getRect());
}
void Player::keyDown(const SDL_Event &eve)
{
    SDL_Rect playerRect = getRect();
    switch (eve.key.keysym.sym)
    {
    case SDLK_LEFT:
        playerRect.x -= 10;
        break;
    case SDLK_RIGHT:
        playerRect.x += 10;
        break;
    case SDLK_UP:
        playerRect.y -= 10;
        break;
    case SDLK_DOWN:
        playerRect.y += 10;
        break;
    default:
        break;
    }
    setRect(playerRect);
}
void Player::keyUp(const SDL_Event &even)
{
}
void Player::tick()
{
    //applyGravity();

    frameCountter++;
    if (frameCountter >= animationSpeed)
    {
        currentFrame = (currentFrame + 1) % 6;
        frameCountter = 0;
    }
}
void Player::applyGravity()
{
    const int gravity = 1;

    SDL_Rect playerRect = getRect();
    playerRect.y += gravity;
    setRect(playerRect);
}
SDL_Texture* Player::activeSpriteSheet() const
{
    return idleSpriteSheet;
}
Player::~Player()
{
}

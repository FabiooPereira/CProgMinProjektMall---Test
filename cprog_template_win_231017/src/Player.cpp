#include "Player.h"

Player::Player(int xPos, int yPos, int w, int h) : Component(xPos, yPos, w, h)
{
    playerImage = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/Player.png").c_str());
}
Player *Player::getInstance(int x, int y, int w, int h)
{
    return new Player(x, y, w, h);
}
void Player::draw() const
{
    SDL_RenderCopy(sys.get_ren(), playerImage, NULL, &getRect());
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
}
Player::~Player()
{
}

#include "Player.h"
#include<iostream>

Player::Player(int xPos, int yPos, int w, int h, bool collision) : Component(xPos, yPos, w, h, collision)
{
    idleSpriteSheet = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/PlayerIdle.png").c_str());

    currentFrame = 0;
    frameCounter = 0;
    animationSpeed = 10;
    velocity = 1;
    jumping = false;
    jumpForce = 5;
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
    SDL_Rect playerRect = getRect();
    applyVelocity(&playerRect);
    setRect(playerRect);
    std::cout << velocity;

    frameCounter++;
    if (frameCounter >= animationSpeed)
    {
        currentFrame = (currentFrame + 1) % 6;
        frameCounter = 0;
    }
}

void Player::applyVelocity(SDL_Rect *rect){
    
    if(jumping){
        jump(jumpForce, rect);
    }
    velocity *= 1.005;
    applyGravity(rect);
}

void Player::jump(int force, SDL_Rect *rect){
    rect -> y -= 100;
    jumping = false;
}

void Player::applyGravity(SDL_Rect *rect){
    rect->y += velocity;
}


void Player::onCollision(Component *c)
{
    jumping = true;

    std::cout << "Hej";
    /*SDL_Rect playerRect = getRect();
    playerRect.y -= 100;
    setRect(playerRect);*/
}
SDL_Texture* Player::activeSpriteSheet() const
{
    return idleSpriteSheet;
}
Player::~Player()
{
}

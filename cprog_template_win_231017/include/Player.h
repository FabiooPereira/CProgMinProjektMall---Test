#ifndef PLAYER_H
#define PLAYER_H
#include "Component.h"
#include <SDL2/SDL.h>
#include "System.h"
#include "Constants.h"
#include <SDL2/SDL_image.h>

class Player : public Component
{
private:
    SDL_Texture *idleSpriteSheet;
    SDL_Texture *RunSpriteSheet;

    int currentFrame;
    int frameCounter;
    int animationSpeed;
    float velocity;
    int jumpForce;
    float gravity;
    bool jumping;

    SDL_Texture *activeSpriteSheet() const;

protected:
    Player(int xPos, int yPos, int w, int h, bool collision);

public:
    static Player *getInstance(int x, int y, int w, int h, bool collision);

    void keyDown(const SDL_Event &eve) override;
    void keyUp(const SDL_Event &eve) override;

    virtual void draw() const override;
    void tick() override;

    void applyGravity(SDL_Rect *rect);
    void applyVelocity(SDL_Rect *rect);
    void jump(int jumpForce, SDL_Rect *rect);
    void onCollision(Component *c)override;

    ~Player();
};

#endif
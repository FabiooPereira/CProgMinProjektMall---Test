#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Component.h"
#include "Constants.h"
#include "System.h"

class Player : public Component
{
public:
    // static Player *getInstance(int x, int y, int w, int h, bool collision);
    static std::shared_ptr<Player> getInstance(int x, int y, int w, int h, bool collision);

    void keyDown(const SDL_Event &eve) override;
    void keyUp(const SDL_Event &eve) override;

    void draw() const override;
    void tick() override;

    void applyGravity();
    void applyVelocity();
    void jump();
    void onCollision(std::shared_ptr<Component> c) override;

    ~Player() override;

protected:
    Player(int xPos, int yPos, int w, int h, bool collision);

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
};

#endif
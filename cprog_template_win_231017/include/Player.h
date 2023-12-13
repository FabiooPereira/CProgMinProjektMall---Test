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
    static std::shared_ptr<Player> getInstance(int x, int y, int w, int h, bool collision);

    void keyDown(const SDL_Event &eve) override;

    void draw() const override;
    void tick() override;

    void applyVelocity();
    void jump();
    void onCollision(std::shared_ptr<Component> c) override;

    // Sprite management
    void setSprite(const std::string &imageFile);
    void setAnimation(int frames);
    void updateFrame();
    ~Player() override;

protected:
    Player(int xPos, int yPos, int w, int h, bool collision);
    float velocity;
    int jumpForce;
    float gravity;
    bool jumping;

private:
    // Sprite management
    SDL_Texture *idleSpriteSheet = nullptr;

    std::string imageFileURL;
    int spriteSheetWidth, spriteSheetHeight; // Dimensions of the entire sprite sheet
    int frameWidth, frameHeight;             // Dimensions of a single frame
    int frameCount;

    int currentFrame;
    int frameCounter;
    int animationSpeed;
    //
};

#endif
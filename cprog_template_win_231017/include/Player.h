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
    int frameCountter;
    int animationSpeed;

    SDL_Texture* activeSpriteSheet() const;

protected:
    Player(int xPos, int yPos, int w, int h);

public:
    static Player *getInstance(int x, int y, int w, int h);

    void keyDown(const SDL_Event &eve);
    void keyUp(const SDL_Event &eve);

    virtual void draw() const override;
    void tick() override;

    void applyGravity();

    ~Player();
};
#endif
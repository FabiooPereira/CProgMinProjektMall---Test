#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL_image.h>
#include "Component.h"
#include <string>


namespace engine
{
    class Player : public Component
    {
    public:
        static std::shared_ptr<Player> getInstance(int x, int y, int w, int h, bool collision);

        void draw() const override;
        void tick() override;

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

        int spriteSheetWidth, spriteSheetHeight; // Dimensions of the entire sprite sheet

        std::string imageFileURL;
        int frameWidth, frameHeight; // Dimensions of a single frame
        int frameCount;

        int currentFrame;
        int frameCounter;
        int animationSpeed;
        //
    };
}

#endif
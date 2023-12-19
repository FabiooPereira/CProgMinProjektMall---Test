#ifndef DOODLEPLAYER_H
#define DOODLEPLAYER_H
#include "Player.h"

class DoodlePlayer : public Player
{
public:
    static std::shared_ptr<DoodlePlayer> getInstance();

    void keyDown(const SDL_Event &eve) final;

    void tick() override;

    void onCollision(std::shared_ptr<Component> c) final;

    void applyVelocity();

    void jump();

private:
    DoodlePlayer();
};

#endif
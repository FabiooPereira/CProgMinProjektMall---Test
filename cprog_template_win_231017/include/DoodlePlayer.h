#ifndef DOODLEPLAYER_H
#define DOODLEPLAYER_H
#include "Player.h"

namespace scribbleHop
{
    class DoodlePlayer : public engine::Player
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
}
#endif
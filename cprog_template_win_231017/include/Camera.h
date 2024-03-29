#ifndef CAMERA_H
#define CAMERA_H

#include "Component.h"

namespace engine
{
    class Camera : public Component
    {
    public:
        static std::shared_ptr<Camera> getInstance(std::shared_ptr<Component> target);

        void draw() const override {}

        void tick() override;
        ~Camera() override;
        static const double getDistanceMoved();

    protected:
        Camera(std::shared_ptr<Component> target);

    private:
        std::shared_ptr<Component> componentToFollow;
        static double distanceMoved;
        double toMove;
    };
}
#endif
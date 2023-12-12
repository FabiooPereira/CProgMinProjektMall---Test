#include "Camera.h"
#include "Session.h"

double Camera::distanceMoved = 0;
Camera::Camera(std::shared_ptr<Component> target) : Component(0, 0, 0, 0), componentToFollow(target)
{
}

std::shared_ptr<Camera> Camera::getInstance(std::shared_ptr<Component> target)
{
    return std::shared_ptr<Camera>(new Camera(target));
}
void Camera::tick()
{
    // cout << "player height:  " << player->getRect().y << endl;
    if (componentToFollow->getRect().y < 400) // om spelaren är väldigt högt upp
    {
        toMove += (450 - componentToFollow->getRect().y); // skynda och flytta kameran
    }
    std::vector<std::shared_ptr<Component>> colliders(ses.getMovables()); // hämta pekare till alla movables
    if (componentToFollow->getRect().y < 450)
    {
        toMove += (450 - componentToFollow->getRect().y) / 60; // FPS; // flytta kameran mjukt och lugnt
        float toMoveThisFrame = toMove / 60;                   // FPS;
        for (std::shared_ptr<Component> c : colliders)
        {
            c->move(0, toMoveThisFrame);
        }
        toMove -= toMoveThisFrame;
        distanceMoved += toMoveThisFrame;
    }
}

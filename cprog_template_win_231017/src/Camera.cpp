#include "Camera.h"
#include "Session.h"

double Camera::distanceMoved=0;
Camera::Camera(Component *component) : Component(0, 0, 0, 0), componentToFollow(component)
{
}

Camera *Camera::getInstance(Component *playerComponent)
{
    return new Camera(playerComponent);
}

void Camera::tick()
{
    // cout << "player height:  " << player->getRect().y << endl;
    if (componentToFollow->getRect().y < 400) // om spelaren är väldigt högt upp
    {
        toMove += (450 - componentToFollow->getRect().y); // skynda och flytta kameran
    }
    std::vector<Component *> colliders(ses.getMovables()); // hämta pekare till alla movables
    if (componentToFollow->getRect().y < 450)
    {
        toMove += (450 - componentToFollow->getRect().y) / 60; // FPS; // flytta kameran mjukt och lugnt
        float toMoveThisFrame = toMove / 60;                   // FPS;
        for (Component *c : colliders)
        {
            c->move(0, toMoveThisFrame);
        }
        toMove -= toMoveThisFrame;
        distanceMoved += toMoveThisFrame;
    }
}

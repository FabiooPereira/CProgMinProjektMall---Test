#include "Camera.h"
#include "Session.h"
#include "SceneManager.h"
#include "System.h"

double Camera::distanceMoved = 0;
Camera::Camera(std::shared_ptr<Component> target) : Component(0, 0, 0, 0), componentToFollow(target)
{
    distanceMoved = 0;
}

std::shared_ptr<Camera> Camera::getInstance(std::shared_ptr<Component> target)
{
    return std::shared_ptr<Camera>(new Camera(target));
}
Camera::~Camera()
{
    // std::cout << "componenttofollow: " << componentToFollow << this << std::endl;
    // std::cout << "camera destructed: " << this << std::endl;
}
void Camera::tick()
{
    if (componentToFollow->getRect().y < 400) // om spelaren är väldigt högt upp
    {
        toMove += (450 - componentToFollow->getRect().y); // skynda och flytta kameran
    }

    if (componentToFollow->getRect().y < 450)
    {
        toMove += (450 - componentToFollow->getRect().y) / System::getfps(); // FPS; // flytta kameran mjukt och lugnt
        float toMoveThisFrame = toMove / System::getfps();                   // FPS;
        for (std::shared_ptr<Component> c : manager->getScene(SceneManager::currentScene)->getComps())
        {
            if (c->isCollider())
                c->move(0, toMoveThisFrame);
        }
        toMove -= toMoveThisFrame;
        distanceMoved += toMoveThisFrame;
    }
}

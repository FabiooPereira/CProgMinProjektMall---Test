#include "Camera.h"
#include "Component.h"
#include "Session.h"
#include "PlatformInstantiator.h"
#include <typeinfo>
#include <memory>
#include "SceneManager.h"
std::shared_ptr<PlatformInstantiator> PlatformInstantiator::getInstance()
{
    return std::shared_ptr<PlatformInstantiator>(new PlatformInstantiator());
}

PlatformInstantiator::PlatformInstantiator() : Component(0, 0, 0, 0), recentDistance(0), platforms(0) {}

void PlatformInstantiator::tick()
{
    createPlatform();
    checkOutOfScope();
}

void PlatformInstantiator::createPlatform()
{
    if ((Camera::distanceMoved - recentDistance) >= distanceInterval && platforms < maxPlatforms) // ser till att det bara finns 12 plattformar och att de inte skapas för ofta
    {
        recentDistance = Camera::distanceMoved;
        int random = 1 + (rand() % 500); // random x position mellan 0 och 500
                                         // reset counter

        std::shared_ptr<Platform> p = Platform::getInstance(random, -5, 120, 20, true); // skapar plattform
        manager->getScene(SceneManager::currentScene)->add(p);                          // lägger till i sessions vektor
        platforms++;                                                                    // håller koll på antal plattformar
    }
}

void PlatformInstantiator::checkOutOfScope()
{
    for (std::shared_ptr<Component> c : manager->getScene(SceneManager::currentScene)->getComps()) // går igenom egna vektorn och kollar om de är utanför fönstret
    {
        std::shared_ptr<Platform> derivedPtr = std::dynamic_pointer_cast<Platform>(c);

        if (derivedPtr)
        {
            if (c->getRect().y > 900) // just nu hårdkodat för jag lyckas inte hämta storleken på skärmen :/
            {
                manager->getScene(SceneManager::currentScene)->remove(c); // lägger till i sessions remove
                // toRemove.push_back(c); // lägger till i egen remove
                platforms--; // håller koll på antal plattformar
                // std::cout << "removed!" << std::endl;
            }
        }
    }
}
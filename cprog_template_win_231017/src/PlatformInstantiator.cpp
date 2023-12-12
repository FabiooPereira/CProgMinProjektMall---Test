#include "Camera.h"
#include "Component.h"
#include "Session.h"
#include "PlatformInstantiator.h"

std::shared_ptr<PlatformInstantiator> PlatformInstantiator::getInstance()
{
    return std::shared_ptr<PlatformInstantiator>(new PlatformInstantiator());
}

PlatformInstantiator::PlatformInstantiator() : Component(0, 0, 0, 0), recentDistance(0), platforms(0) {}

void PlatformInstantiator::tick()
{
    createPlatform();
    checkOutOfScope();
    removeOutOfScope();
}

void PlatformInstantiator::createPlatform()
{
    if ((Camera::distanceMoved - recentDistance) >= distanceInterval && platforms < maxPlatforms) // ser till att det bara finns 12 plattformar och att de inte skapas för ofta
    {
        recentDistance = Camera::distanceMoved;
        int random = 1 + (rand() % 500); // random x position mellan 0 och 500
                                         // reset counter

        std::shared_ptr<Platform> p = Platform::getInstance(random, -5, 120, 20, true); // skapar plattform
        objects.push_back(p);                                                           // lägger till i egen vektor
        ses.add(p);                                                                     // lägger till i sessions vektor
        platforms++;                                                                    // håller koll på antal plattformar
    }
}

void PlatformInstantiator::checkOutOfScope()
{
    for (std::shared_ptr<Platform> c : objects) // går igenom egna vektorn och kollar om de är utanför fönstret
    {
        if (c->getRect().y > 900) // just nu hårdkodat för jag lyckas inte hämta storleken på skärmen :/
        {
            ses.remove(c);         // lägger till i sessions remove
            toRemove.push_back(c); // lägger till i egen remove
            platforms--;           // håller koll på antal plattformar
            // std::cout << "removed!" << std::endl;
        }
    }
}

void PlatformInstantiator::removeOutOfScope()
{
    for (std::shared_ptr<Platform> c : toRemove) // itererar och tar bort plattformar
    {
        for (std::vector<std::shared_ptr<Platform>>::iterator i = objects.begin();
             i != objects.end();)
        {
            if (*i == c)
            {
                i = objects.erase(i);
            }
            else
            {
                i++;
            }
        }
    }
    toRemove.clear();
}
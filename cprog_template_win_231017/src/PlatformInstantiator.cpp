#include "Camera.h"
#include "Component.h"
#include "Session.h"
#include "PlatformInstantiator.h"
#include "SceneManager.h"
#include "System.h"

namespace scribbleHop
{
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
        int randNum = rand() % (350 - minDistanceInterval + 1) + minDistanceInterval;             // hopphöjden är 465 beräknad av fabio, maxintervallet innan en plattform instantieras satte vi till 425
        if ((engine::Camera::getDistanceMoved() - recentDistance) >= randNum && platforms < maxPlatforms) // ser till att det bara finns 12 plattformar och att de inte skapas för ofta
        {
            recentDistance = engine::Camera::getDistanceMoved();
            int random = 1 + (rand() % 380); // random x position mellan 0 och 500
                                             // reset counter

            engine::manager->getScene(engine::SceneManager::getCurrentScene())->add(Platform::getInstance(random, -5, 120, 20, true)); // skapar plattform och lägger till i sessions vektor
            platforms++;                                                                                               // håller koll på antal plattformar
        }
    }

    void PlatformInstantiator::checkOutOfScope()
    {
        for (std::shared_ptr<Component> c : engine::manager->getScene(engine::SceneManager::getCurrentScene())->getComps()) // går igenom egna vektorn och kollar om de är utanför fönstret
        {
            std::shared_ptr<Platform> derivedPtr = std::dynamic_pointer_cast<Platform>(c); // kollar varje komponent är en plattform

            if (derivedPtr) // om static cast fungerar det true annars är det nnull och därför false
            {
                if (c->getRect().y > engine::sys.get_height())
                {
                    engine::manager->getScene(engine::SceneManager::getCurrentScene())->remove(c); // lägger till i sessions remove
                    platforms--;                                                   // håller koll på antal plattformar
                }
            }
        }
    }
}
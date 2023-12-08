#include "PlatformInstantiator.h"
#include "Platform.h"
#include "Session.h"
#include "Camera.h"
#include "Component.h"


PlatformInstantiator *PlatformInstantiator::getInstance()
{
    return new PlatformInstantiator();
}

PlatformInstantiator::PlatformInstantiator() : Component(0, 0, 0, 0), recentDistance(0), platforms(0) {}

// Player::Player(int xPos, int yPos, int w, int h, bool collision) : Component(xPos, yPos, w, h, collision)
// {
//     idleSpriteSheet = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/Player_Idle.png").c_str());

//     currentFrame = 0;
//     frameCounter = 0;
//     animationSpeed = 10;
//     velocity = 1;
//     jumping = false;
//     jumpForce = 30; // Adjust the jump force as needed
//     gravity = 1.05; // Adjust the gravity as needed
// }

// Player *Player::getInstance(int x, int y, int w, int h, bool collision)
// {
//     return new Player(x, y, w, h, collision);
// }
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

        Platform *platf = Platform::getInstance(random, -50, 100, 20, true); // skapar plattform
        objects.push_back(platf);                                            // lägger till i egen vektor
        ses.add(platf);                                                      // lägger till i sessions vektor
        platforms++;                                                         // håller koll på antal plattformar
    }
}
void PlatformInstantiator::checkOutOfScope()
{
    for (Component *c : objects) // går igenom egna vektorn och kollar om de är utanför fönstret
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
    for (Component *c : toRemove) // itererar och tar bort plattformar
    {
        for (std::vector<Component *>::iterator i = objects.begin();
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
void PlatformInstantiator::draw()const{

}
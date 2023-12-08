#include <iostream>
#include <string>
#include "Session.h"
#include "Label.h"
#include "Button.h"
#include "Player.h"
#include "Platform.h"
#include <SDL2/SDL.h>
#include "Camera.h"
#include "PlatformInstantiator.h"
#define FPS 60
using namespace std;
Session ses;
int value = 0;
double distanceMoved;

class OkaKnapp : public Button
{
public:
    OkaKnapp(Label *lbl) : Button(100, 300, 70, 70, "Öka"), label(lbl) {}

    void perform(Button *source)
    {
        value++;
        label->setText(to_string(value));
    }

private:
    Label *label;
};
class MinskaKnapp : public Button
{
public:
    MinskaKnapp(Label *lbl) : Button(500, 300, 70, 70, "Minska"), label(lbl) {}

    void perform(Button *source)
    {
        value--;
        label->setText(to_string(value));
    }

private:
    Label *label;
};

// class Camera : public Component
// {
// public:
//     static Camera *getInstance(Component *playerComponent)
//     {
//         return new Camera(playerComponent);
//     }

//     void draw() const {}

//     void tick()
//     {
//         // cout << "player height:  " << player->getRect().y << endl;
//         if (componentToFollow->getRect().y < 400) // om spelaren är väldigt högt upp
//         {
//             toMove += (450 - componentToFollow->getRect().y); // skynda och flytta kameran
//         }
//         std::vector<Component *> colliders(ses.getMovables()); // hämta pekare till alla movables
//         if (componentToFollow->getRect().y < 450)
//         {
//             toMove += (450 - componentToFollow->getRect().y) / FPS; // flytta kameran mjukt och lugnt
//             float toMoveThisFrame = toMove / FPS;
//             for (Component *c : colliders)
//             {
//                 c->move(0, toMoveThisFrame);
//             }
//             toMove -= toMoveThisFrame;
//             distanceMoved += toMoveThisFrame;
//         }
//     }

// protected:
//     Camera(Component *component) : Component(0, 0, 0, 0), componentToFollow(component)
//     {
//     }

// private:
//     Component *componentToFollow;
//     float toMove;
// };

// class PlatformInstantiator : public Component // instantierar plattformar
// {
// public:
//     static PlatformInstantiator *getInstance()
//     {
//         return new PlatformInstantiator();
//     }

//     PlatformInstantiator() : Component(0, 0, 0, 0), platforms(0) {}

//     void draw() const {}

//     void tick()
//     {
//         createPlatform();
//         checkOutOfScope();
//         removeOutOfScope();
//     }

// private:
//     void createPlatform()
//     {
//         if ((distanceMoved - recentDistance) >= distanceInterval && platforms < maxPlatforms) // ser till att det bara finns 12 plattformar och att de inte skapas för ofta
//         {
//             recentDistance = distanceMoved;
//             int random = 1 + (rand() % 500); // random x position mellan 0 och 500
//                                              // reset counter

//             Platform *platf = Platform::getInstance(random, -50, 100, 20, true); // skapar plattform
//             objects.push_back(platf);                                            // lägger till i egen vektor
//             ses.add(platf);                                                      // lägger till i sessions vektor
//             platforms++;                                                         // håller koll på antal plattformar
//         }
//     }
//     void checkOutOfScope()
//     {
//         for (Component *c : objects) // går igenom egna vektorn och kollar om de är utanför fönstret
//         {
//             if (c->getRect().y > 900) // just nu hårdkodat för jag lyckas inte hämta storleken på skärmen :/
//             {
//                 ses.remove(c);         // lägger till i sessions remove
//                 toRemove.push_back(c); // lägger till i egen remove
//                 platforms--;           // håller koll på antal plattformar
//                 // std::cout << "removed!" << std::endl;
//             }
//         }
//     }
//     void removeOutOfScope()
//     {
//         for (Component *c : toRemove) // itererar och tar bort plattformar
//         {
//             for (vector<Component *>::iterator i = objects.begin();
//                  i != objects.end();)
//             {
//                 if (*i == c)
//                 {
//                     i = objects.erase(i);
//                 }
//                 else
//                 {
//                     i++;
//                 }
//             }
//         }
//         toRemove.clear();
//     }
//     float recentDistance;
//     const int distanceInterval = 50;
//     int platforms;
//     int maxPlatforms = 16;
//     std::vector<Component *> objects;
//     std::vector<Component *> toRemove;
// };

int main(int argv, char **args)
{
    // Fab
    PlatformInstantiator *pi = PlatformInstantiator::getInstance();
    ses.add(pi);

    Platform *platform = Platform::getInstance(200, 880, 100, 20, true);
    ses.add(platform);

    Platform *platform2 = Platform::getInstance(150, 600, 100, 20, true);
    ses.add(platform2);

    Platform *platform3 = Platform::getInstance(100, 300, 100, 20, true);
    ses.add(platform3);

    Platform *platform4 = Platform::getInstance(200, 200, 100, 20, true);
    ses.add(platform4);

    Platform *platform5 = Platform::getInstance(150, 100, 100, 20, true);
    ses.add(platform5);

    Platform *platform6 = Platform::getInstance(100, 50, 100, 20, true);
    ses.add(platform6);

    Player *player = Player::getInstance(250, 850, 100, 100, true);
    ses.add(player);

    Camera *camera = Camera::getInstance(player);
    ses.add(camera);

    ses.run();
    std::cout << "after run()";
    return 0;
}

/*

0.0									500.0


            200.150







0.900								500.900


            450 - 200 = 250

*/
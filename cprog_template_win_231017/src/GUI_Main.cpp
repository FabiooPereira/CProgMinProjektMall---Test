#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "Session.h"
// #include "Label.h"
// #include "Button.h"
#include "Player.h"
#include "Platform.h"
#include "Camera.h"
#include "PlatformInstantiator.h"

#define FPS 60
using namespace std;

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
    {
        Player *test = Player::getInstance(0, 0, 0, 0, false);
        Player::getInstance(0, 0, 0, 0, false);
    }
    Camera *camera = Camera::getInstance(player);
    ses.add(camera);

    ses.run();
    std::cout << "after run()";
    return 0;
}

// class OkaKnapp : public Button
// {
// public:
//     OkaKnapp(Label *lbl) : Button(100, 300, 70, 70, "Öka"), label(lbl) {}

//     void perform(Button *source)
//     {
//         value++;
//         label->setText(to_string(value));
//     }

// private:
//     Label *label;
// };

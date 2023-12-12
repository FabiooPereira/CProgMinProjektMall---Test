#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <memory>
#include "Session.h"
#include "Label.h"
#include "Button.h"
#include "Player.h"
#include "Platform.h"
#include "Camera.h"
#include "PlatformInstantiator.h"
#include "MasterMixer.h"

#define FPS 60
using namespace std;

void createDoodleJumpComponents();

int main(int argv, char **args)
{
    createDoodleJumpComponents();

    ses.run();
    std::cout << "after run()" << std::endl;
    Component::printCounts();

    return 0;
}

void createDoodleJumpComponents()
{

    Mix_Music *bgMusic = mixer->loadMusic("BacgroundMusic_489035__michael-db__game-music-01.wav");
    mixer->playMusic(bgMusic);

    ses.add(PlatformInstantiator::getInstance());

    ses.add(Platform::getInstance(200, 880));

    ses.add(Platform::getInstance(150, 600));

    ses.add(Platform::getInstance(100, 300));

    ses.add(Platform::getInstance(200, 200));

    ses.add(Platform::getInstance(150, 100));

    ses.add(Platform::getInstance(100, 50));

    shared_ptr<Player> player = Player::getInstance(250, 850, 100, 100, true);
    ses.add(player);
    ses.add(Camera::getInstance(player));
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

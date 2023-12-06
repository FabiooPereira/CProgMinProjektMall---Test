#include <iostream>
#include <string>
#include "Session.h"
#include "Label.h"
#include "Button.h"
#include "Player.h"
#include "platform.h"
#include <SDL2/SDL.h>

using namespace std;
using namespace engine;
using namespace game;
Session ses;
int value = 0;

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

class PlatformInstantiator : public Component
{
public:
    static PlatformInstantiator *getInstance(int x, int y, int w, int h)
    {
        return new PlatformInstantiator(x, y, w, h);
    }
    PlatformInstantiator(int x, int y, int w, int h) : Component(x, y, w, h)
    {
    }
    void draw() const
    {
    }

    void tick()
    {
        counter++;
        if (counter >= 40)
        {
            int random = 1 + (rand() % 500);
            counter = 0;
            Platform *platf = Platform::getInstance(random, 100, 100, 20, true);
            ses.add(platf);
        }
    }

private:
    int counter;
};

class Camera : public Component
{
public:
    static Camera *getInstance(int x, int y, int w, int h, Player *playerComponent)
    {
        return new Camera(x, y, w, h, playerComponent);
    }

    void draw() const
    {
    }

    void tick()
    {
        cout << "player height:  " << player->getRect().y << endl;

        if (player->getRect().y < 450)
        {
            for (Component *c : ses.colliders)
            {
                SDL_Rect platformRect = c->getRect();
                platformRect.y += 3;
                c->setRect(platformRect);
            }
        }
    }

protected:
    Camera(int x, int y, int w, int h, Player *playerComponent) : Component(x, y, w, h), player(playerComponent)
    {
    }

private:
    Player *player;
};

int main(int argv, char **args)
{
    // Fab
    PlatformInstantiator *pi = PlatformInstantiator::getInstance(0, 0, 0, 0);
    ses.add(pi);

    Platform *platform = Platform::getInstance(200, 200, 100, 20, true);
    ses.add(platform);

    Player *player = Player::getInstance(200, 150, 100, 100, true);
    ses.add(player);

    Camera *camera = Camera::getInstance(0, 0, 0, 0, player);
    ses.add(camera);




    // Label *lbl = Label::getInstance(300, 300, 500, 50, "0");
    // std::cout << lbl;
    // ses.add(lbl);

    // Button *btn = new OkaKnapp(lbl);
    // ses.add(btn);

    // Button *btn2 = new MinskaKnapp(lbl);
    // ses.add(btn2);

    ses.run();
    return 0;
}
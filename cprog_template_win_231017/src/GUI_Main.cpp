#include <iostream>
#include <string>
#include "Session.h"
#include "Label.h"
#include "Button.h"
#include "Player.h"
#include "Platform.h"
#include <SDL2/SDL.h>

using namespace std;
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
        // cout << "player height:  " << player->getRect().y << endl;
        if (player->getRect().y < 250)
        {
            toMove += (450 - player->getRect().y);
        }
        else if (player->getRect().y < 450)
        {
            toMove += (450 - player->getRect().y) / 60;
        }
        std::vector<Component *> colliders(ses.getMovables());
        for (Component *c : colliders)
        {
            SDL_Rect platformRect = c->getRect();
            platformRect.y += toMove / 60;
            c->setRect(platformRect);

            toMove -= toMove / 60;
        }
    }

protected:
    Camera(int x, int y, int w, int h, Player *playerComponent) : Component(x, y, w, h), player(playerComponent)
    {
    }

private:
    Player *player;
    int toMove;
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
        std::cout << counter << endl;
        if (counter >= 10 && platforms < 12)
        {
            int random = 1 + (rand() % 500);
            counter = 0;

            Platform *platf = Platform::getInstance(random, 100, 100, 20, true);
            objects.push_back(platf);
            ses.add(platf);
            platforms++;
        }

        for (Component *c : objects)
        {
            if (c->getRect().y > 900)
            {
                ses.remove(c);
                toRemove.push_back(c);
                platforms--;
                std::cout << "removed!" << std::endl;
            }
        }

        for (Component *c : toRemove)
        {
            for (vector<Component *>::iterator i = objects.begin();
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

private:
    int counter;
    int platforms;
    std::vector<Component *> objects;
    std::vector<Component *> toRemove;
};

int main(int argv, char **args)
{
    // Fab
    PlatformInstantiator *pi = PlatformInstantiator::getInstance(0, 0, 0, 0);
    ses.add(pi);

    Platform *platform = Platform::getInstance(200, 650, 100, 20, true);
    ses.add(platform);

    Platform *platform2 = Platform::getInstance(100, 250, 100, 20, true);
    ses.add(platform2);

    Player *player = Player::getInstance(200, 600, 100, 100, true);
    ses.add(player);

    Camera *camera = Camera::getInstance(0, 0, 0, 0, player);
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
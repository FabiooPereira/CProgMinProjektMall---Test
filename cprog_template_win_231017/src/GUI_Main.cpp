#include <iostream>
#include <string>
#include "Session.h"
#include "Label.h"
#include "Button.h"
#include "Player.h"
#include "platform.h"
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

class PlatformInstantiator : public Component
{
public:

    PlatformInstantiator(int x, int y, int w, int h) : Component(x, y, w, h)
    {
    }
    void draw() const
    {
    }

    void tick()
    {
        // Platform *platf = Platform::getInstance(20, 80, 500, 50, true);
        // ses.add(platf);
    }
};

int main(int argv, char **args)
{
    // Fab
    // PlatformInstantiator pi(0, 0, 0, 0);
    // ses.add(&pi);

    Platform *platform = Platform::getInstance(200, 800, 500, 50, true);
    ses.add(platform);

    Platform *platform1 = Platform::getInstance(400, 400, 500, 50, true);
    ses.add(platform1);

    Player *player = Player::getInstance(400, 400, 100, 100, true);
    ses.add(player);

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
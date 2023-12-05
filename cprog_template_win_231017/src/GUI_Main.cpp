#include <iostream>
#include <string>
#include "Session.h"
#include "Label.h"
#include "Button.h"
#include "Player.h"
#include "platform.h"
#include <SDL2/SDL.h>

using namespace std;

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

int main(int argv, char** args)
{
    //Fab
    Session ses;

    Platform* platform = Platform::getInstance(200, 800, 500, 50, true);
    ses.add(platform);


    Label *lbl = Label::getInstance(300, 300, 500, 50, "0");
    std::cout << lbl;
    ses.add(lbl);

    Button *btn = new OkaKnapp(lbl);
    ses.add(btn);

    Button *btn2 = new MinskaKnapp(lbl);
    ses.add(btn2);

    Player *player = Player::getInstance(300,300, 100,100, true);
    ses.add(player);

    std::cout << std::endl << ses.colliders[0] << std::endl << ses.colliders[1] << std::endl << player << std::endl << platform;

    ses.run();
    return 0;
}
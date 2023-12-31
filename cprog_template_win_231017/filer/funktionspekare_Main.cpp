#include <iostream>
#include <string>
#include "Session.h"
#include "Label.h"
#include "Button.h"
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
    Label* getLabel(){ return label;}

private:
    Label *label;
};

int main(int argv, char** args)
{
    //Fab
    //void (*fpek) (MinskaKnapp*) = insult;

    Session ses;
    Label *lbl = Label::getInstance(300, 300, 50, 50, "0");
    std::cout << lbl;
    ses.add(lbl);

    Button *btn = new OkaKnapp(lbl);
    ses.add(btn);

    Button *btn2 = new MinskaKnapp(lbl);
    ses.add(btn2);

    ses.run();
    return 0;
}
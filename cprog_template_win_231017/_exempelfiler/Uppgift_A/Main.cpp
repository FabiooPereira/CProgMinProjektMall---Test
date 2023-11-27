#include "Elefant.h"
#include <iostream>

using namespace zoo;

int main(){
    Elefant* elefants[3];
    elefants[0] = new Elefant("Jumbo", 600, 170);
    elefants[1] = new Elefant("Mumbo", 500, 160);
    elefants[2] = new Elefant("Lillen", 800, 200);

    for (int i = 0; i < 3; i++)
    {
        printElefant(elefants[i]);
    }
    // Elefant* el = new zoo::Elefant("Fabio", 34 , 50);

    // printElefant(el);
    std::cout << "Hello";
    return 0;
}
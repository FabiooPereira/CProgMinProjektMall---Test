#include "Elephant.h"

Elephant::Elephant(std::string n, int w, int tl):AnimalE(n,w), trunkLength(tl){}
int Elephant::getTrunkLength()const{
    return trunkLength;
}
Elephant* Elephant::createElephant(std::string n, int w, int tl){
    return new Elephant(n,w,tl);
}
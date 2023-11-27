#ifndef ELEPHANT_H
#define ELEPHANT_H

#include "AnimalE.h"

class Elephant: public AnimalE
{
private:
    int trunkLength;
    Elephant(std::string n , int w, int tl);
    
public:
    static Elephant* createElephant(std::string n,int w, int tl);
    int getTrunkLength() const;
};
#endif


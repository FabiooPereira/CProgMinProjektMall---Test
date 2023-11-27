#ifndef BLABARSSNAR_H
#define BLABARSSNAR_H

#include "Mat.h"

class Blabarssnar : public Mat 
{
private:
    Blabarssnar(int w, int s, int a);
    int surface;
public:
    static Blabarssnar* createBlabarssnar(int w, int s, int a);
    ~Blabarssnar();
    virtual int CalculateNutrientContent() const override;
};
#endif
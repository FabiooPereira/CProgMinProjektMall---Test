#ifndef MYRSTACK_H
#define MYRSTACK_H

#include "Mat.h"
class Myrstack: public Mat
{
private:
    int numOfAnts;
    Myrstack(int weight, int numOfAnts);
public:
    static Myrstack* createMyrstack(int weight, int numOfAnts);
    virtual int CalculateNutrientContent() const override;
    ~Myrstack();
};

#endif
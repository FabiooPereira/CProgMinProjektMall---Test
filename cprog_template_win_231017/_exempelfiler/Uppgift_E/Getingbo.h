#ifndef GETINGBO_H
#define GETINGBO_H

#include "Mat.h"
class Getingbo : public Mat
{
private:
    bool full;
    Getingbo(int w, bool b);
public:
    static Getingbo* createGetingbo(int w, bool b);
    virtual int CalculateNutrientContent() const override;
    ~Getingbo();
};
#endif
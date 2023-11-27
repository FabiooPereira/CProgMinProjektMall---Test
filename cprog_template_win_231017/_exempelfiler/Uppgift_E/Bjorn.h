#ifndef BJORN_H
#define BJORN_H

#include <vector>
#include "Mat.h"
class Bjorn
{
private:
    int weight;
public:
    virtual void eats(const std::vector<Mat*>& food);
    int getWeight()const;
    void setWeight(int w);
    ~Bjorn();
protected:
     Bjorn(int w);
};

#endif
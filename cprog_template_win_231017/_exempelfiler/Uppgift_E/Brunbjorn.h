#ifndef BRUNBJORN_H
#define BRUNBJORN_H

#include "Bjorn.h"

class Brunbjorn : public Bjorn
{
private:
    Brunbjorn(int w);
public:
    static Brunbjorn* createBrunbjorn(int w);
    void eats(const std::vector<Mat*>& food) override;
    ~Brunbjorn();
};
#endif
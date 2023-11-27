#ifndef GRIZZLYBJORN_H
#define GRIZZLYBJORN_H

#include "Bjorn.h"
class Grizzlybjorn: public Bjorn
{
private:
    Grizzlybjorn(int w);
public:
    static Grizzlybjorn* createGrizzlybjorn(int w);
    void eats(const std::vector<Mat*>& food) override;
    Myrstack* findHeaviestMyrstack(const std::vector<Myrstack*>& myrstacks) const;
    ~Grizzlybjorn();
};
#endif
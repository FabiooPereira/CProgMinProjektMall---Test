#ifndef ELEFANT_H
#define ELEFANT_H

#include "Animal.h"
namespace zoo
{
    class Elefant : public Animal
    {
    private:
        int trunk;
    public:
        Elefant(std::string name, int weight, int trunkLenght);
        ~Elefant();

        int getTrunk()const;
       
    };
     void printElefant(const Elefant* ele);
} // namespace zoo

#endif
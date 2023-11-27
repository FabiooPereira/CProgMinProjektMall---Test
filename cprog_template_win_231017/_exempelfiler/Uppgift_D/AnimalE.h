#ifndef ANIMALE_H
#define ANIMAL_H

#include<string>

class AnimalE
{
private:
    std:: string name;
    int weight;
public:
    
    std::string getName() const;
    int getWeight() const;
    ~AnimalE();
protected:
    AnimalE(std::string n, int w);
};
#endif
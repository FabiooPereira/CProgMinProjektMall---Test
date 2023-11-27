#include "Animal.h"
namespace zoo
{
    Animal::Animal(std::string n, int w):name(n), weight(w){}

    std::string Animal::getName() const{
        return name;
    }

    int Animal::getWeight() const{
        return weight;
    }
} // namespace zoo

#include "AnimalE.h"

AnimalE::AnimalE(std::string n, int w): name(n), weight(w){}

AnimalE::~AnimalE(){}

std::string AnimalE::getName() const{
    return name;
}

int AnimalE::getWeight() const{
    return weight;
}
#include "Bjorn.h"

Bjorn::Bjorn(int w): weight(w){}
void Bjorn::eats(const std::vector<Mat*>& food){};
int Bjorn::getWeight()const{
    return weight;
}

void Bjorn::setWeight(int w){
    weight = w;
}


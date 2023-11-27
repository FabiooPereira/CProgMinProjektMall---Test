#include "Myrstack.h"

Myrstack::Myrstack(int w, int ants): Mat(w,0), numOfAnts(ants){}

Myrstack* Myrstack::createMyrstack(int w,int ants){
    return new Myrstack(w, ants);
}

int Myrstack::CalculateNutrientContent() const{
    return Mat::getWeight() + numOfAnts;
}
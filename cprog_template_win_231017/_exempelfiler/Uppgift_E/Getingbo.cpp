#include "Getingbo.h"

Getingbo::Getingbo(int w, bool b):Mat(w, b ?10:4), full(b) {
}
Getingbo* Getingbo::createGetingbo(int w,bool b){
    return new Getingbo(w,b);
}
int Getingbo::CalculateNutrientContent() const{
    if(full){
        return Mat::getWeight() *2;
    }else{
        return Mat::getWeight() / 2;
    }
}
#include "Blabarssnar.h"

Blabarssnar::Blabarssnar(int w, int s, int a): Mat(w,s), surface(a){

}
Blabarssnar* Blabarssnar::createBlabarssnar(int w, int s,int a){
    return new Blabarssnar(w,s,a);
}
int Blabarssnar::CalculateNutrientContent()const{
    int tmp = Mat::getWeight();
    return tmp / surface;
}
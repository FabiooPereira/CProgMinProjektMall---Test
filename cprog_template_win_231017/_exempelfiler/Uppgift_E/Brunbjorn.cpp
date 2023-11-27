#include "Brunbjorn.h"

Brunbjorn::Brunbjorn(int w): Bjorn(w){}
Brunbjorn* Brunbjorn::createBrunbjorn(int w){
    return new Brunbjorn(w);
}
void Brunbjorn::eats(const std::vector<Mat*>& food){
    if(!food.empty()){
        Mat* chosenFood = food.front();
        for (Mat* m : food)
        {
            if(m->getWeight()>chosenFood->getWeight()){
                chosenFood = m;
            }
        }

        setWeight((int)((chosenFood->CalculateNutrientContent())*0.25f));
    }
    
}
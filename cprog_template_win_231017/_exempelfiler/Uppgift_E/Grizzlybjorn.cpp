#include "Grizzlybjorn.h"
#include "Myrstack.h"

Grizzlybjorn::Grizzlybjorn(int w):Bjorn(w){}
Grizzlybjorn* Grizzlybjorn::createGrizzlybjorn(int w){
    return new Grizzlybjorn(w);
}
void Grizzlybjorn::eats(const std::vector<Mat*>& food){
    std::vector<Myrstack*> myrstacks;

    for(auto it = food.begin(); it != food.end(); ++it){
        Myrstack* myrstack = dynamic_cast<Myrstack*>(*it);
        if (myrstack)   
        {
            myrstacks.push_back(myrstack);
        }
        
    }
    
    Myrstack* heaviestMyrstack = findHeaviestMyrstack(myrstacks);
    if(heaviestMyrstack){
        setWeight(heaviestMyrstack->CalculateNutrientContent()*0.25);
        delete heaviestMyrstack;
    }
}
Myrstack* GrizzlyBear::findHeaviestMyrstack(const std::vector<Myrstack*>& myrstacks) const {
    Myrstack* heaviestMyrstack = nullptr;
    int maxWeight = 0;

    // Iterate through the vector to find the heaviest Myrstack
    for (const auto& myrstack : myrstacks) {
        int myrstackWeight = myrstack->getWeight();
        if (myrstackWeight > maxWeight) {
            maxWeight = myrstackWeight;
            heaviestMyrstack = myrstack;
        }
    }

    return heaviestMyrstack;
}
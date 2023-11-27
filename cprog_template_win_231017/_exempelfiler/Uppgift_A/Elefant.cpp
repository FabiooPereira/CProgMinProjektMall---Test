#include "Elefant.h"
#include<iostream>
namespace zoo
{
    Elefant::Elefant(std::string name, int weight, int trunkLenght):Animal(name, weight),trunk(trunkLenght){
    }
    int Elefant::getTrunk()const{
        return trunk;
    }
    void printElefant(const Elefant* ele){
        std::cout<< ele->getName() << " "
                << ele->getWeight() << " " 
                << ele->getTrunk()<< std::endl; 
    }
} // namespace zoo

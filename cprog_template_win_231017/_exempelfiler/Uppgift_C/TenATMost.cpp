#include "TenAtmost.h"

int TenAtMost::objectCount = 0;

TenAtMost::TenAtMost(std::string n):name(n){
    if(objectCount>= 10){
        throw std::out_of_range("Maximun object limit reached 10obj");
    }
    objectCount++;
}
std::string TenAtMost::getName() const{
    return name;
}
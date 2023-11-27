// Labb2, IntVector.cpp – definitioner av icke-triviala medlemsfunktioner

//HEJ

#include "IntVector.h"

//Default konstruktor
IntVector::IntVector(): data(nullptr), sizeOfVector(2){}
//Copy konstruktor
IntVector::IntVector(const IntVector& other): data(nullptr), sizeOfVector(other.sizeOfVector){
    data = new int[sizeOfVector];

    for(int i = 0; i <sizeOfVector; i++){
        data[i] = other.data[i];
    }
}
//Move konstruktor
IntVector::IntVector(IntVector&& other): data(other.data), sizeOfVector(other.sizeOfVector){
    other.data= nullptr;
    other.sizeOfVector = 0;
}
//Konstruktor med init lista
IntVector::IntVector(const std::initializer_list<int> &values):data(nullptr), sizeOfVector(0){
    if(values.size()>0){
        data = new int[values.size()];
        sizeOfVector = values.size();

        int* current = data;
        for(int value : values){
            *current = value;
            ++current;
        }
        
    }

}
//Tilldelningsoperator
IntVector& IntVector::operator=(const IntVector& other){
    if(this != &other){
        delete[] data;
        data = new int[other.sizeOfVector];
        sizeOfVector = other.sizeOfVector;

        for (int i = 0; i < sizeOfVector; i++)
        {
            data[i] = other.data[i];
        }
        
    }
    return *this;
}
//Flyttoperator
IntVector& IntVector::operator=(IntVector&& other){
    if(this != &other){
        delete[] data;

        data = other.data;
        sizeOfVector = other.sizeOfVector;

        other.data = nullptr;
        other.sizeOfVector = 0;
    }
    return *this; 
}
//Destruktor
IntVector::~IntVector(){
    delete[] data;
}
//Indexoperator
int& IntVector::operator[](int index){
    return data[index];
}
//Konstant indexoperator
const int& IntVector::operator[](int index) const{
    return data[index];
}
//PushBack funktion
void IntVector::push_back(int value){
    int* newData = new int[sizeOfVector+1];

    for(int i=0;  i<sizeOfVector; i++){
        newData[i] = data[i];
    }
    newData[sizeOfVector] = value;

    delete[] data;
    data = newData;
    sizeOfVector++;
}
//sizeOfVector funktion
const int IntVector::size()const{
    return sizeOfVector;
}
//Utskriftsoperator överlagring
std::ostream& operator<<(std::ostream& os, const IntVector& v) {
    for (int i = 0; i < v.sizeOfVector; ++i) {
        os << v.data[i] << " ";
    }
    return os;
}
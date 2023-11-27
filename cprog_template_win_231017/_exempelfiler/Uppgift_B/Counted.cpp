#include "Counted.h"

int Counted::count = 0;

Counted::Counted(std::string d) : data(d) {
    count++;
}
//copykonstruktor
Counted::Counted(const Counted& other) : data(other.data){
  count++;
}
Counted::~Counted() {
    count--;
}

std::string Counted::get() const {
    return data;
}

int Counted::getCount() {
    return count;
}
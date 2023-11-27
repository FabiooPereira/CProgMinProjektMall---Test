// Labb2, IntVector.h – klassdefinition
#ifndef INTVECTOR_H
#define INTVECTOR_H
#include <initializer_list>
#include <iostream>

class IntVector
{
private:
    int *data;
    int sizeOfVector;

public:
    IntVector();
    IntVector(const IntVector &other);                   // Copykonstruktor
    IntVector(IntVector &&other);                        // Movekkonstruktor
    IntVector(const std::initializer_list<int> &values); // KOntruktor med initieringsLista
    ~IntVector();                                        // Destruktor

    IntVector &operator=(const IntVector &other); // Koperingsoperator
    IntVector &operator=(IntVector &&other);      // Flyttoperator

    int &operator[](int index);
    const int &operator[](int index) const;

    void push_back(int value);
    const int size() const;

    friend std::ostream& operator<<(std::ostream& os, const IntVector& v);

protected:
};
#endif
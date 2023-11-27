#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

namespace zoo
{
    class Animal
    {
    private:
        std::string name;
        int weight;
    public:
        Animal(std::string n, int w);
        ~Animal();

        std::string getName() const;
        int getWeight() const;
    };
} // namespace ZOO

#endif
